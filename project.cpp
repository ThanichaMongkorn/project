#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include<iomanip>

using namespace std;

void start(){
    cout << "          ____________________________________\n";
    cout << "         |                                    |\n";
    cout << "         |   J O I N  T O  T H E  W O R L D   |\n";
    cout << "         |____________________________________|\n";
    cout << "                ========================\n";
    cout << "                      ===========\n";
    cout << "                         =====\n";
    cout << "                           =\n";
    cout << "\n-----------------------------------------------------------\n";
    cout << "|   WARNING! YOU SHOULD READ 'HOW TO PLAY' TILL THE END   |\n";
    cout << "-----------------------------------------------------------\n";
    cout << "\n-------------------\n";
    cout << "|   HOW TO PLAY   |\n";
    cout << "-------------------\n";
    cout << "\nm == match\ns == steal\np == protect\ne == exit\n";
    cout << "\n1. Player will randomly receive 5 cards.\n";
    cout << "\n2. Initially, must match cards of the same color. After that, there will always be 5 cards in the hand.\n";
    cout << "\n3. If the card in hand cannot be matched, the player needs to draw 1 card and discard it.\n";
    cout << "\n4. At the beginning, the player and the bot must match the card before they can steal the other's card\n";
    cout << "\n5. Stealing a card can only steal the last pair that the other party has matched by using a card \nthat has the same color as the card that we will steal, and the other party can block the card as well. \n";
    cout << "\n6. The protection condition is if the player can defend and will not lose the card and will also get the player's card to steal.\n";
    cout << "\n7. If the player wants to defend, there will be a choice when choosing whether to take action.  Steal or match or defend\n";
    cout << "\n8. The game ends when the community cards run out and the cards of the matched players are added together and find a winn\n";
    
    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
}
	

//????? Class ??????? cards money + color
class Card {
        public:
        string color;
        int money;
        Card(string, int);
};
Card::Card(string c, int m )
    {
        color = c;
        money = m;
}


// ????? Deck ?????? ????????????
class Deck {
        public:
        vector<Card> cards;
        Deck();
        void shuffle()
        {
// ???????????????
        random_shuffle(cards.begin(), cards.end());
        }
//????????????????
        void ShowAllCards()
        {
            for (int i = 0; i < cards.size(); i++)
            {
            cout << cards[i].money << " " << cards[i].color << endl;
        }
    }
};


Deck::Deck() {
// ?????????? ???? ??????? ??????? 10 ??
        for (int i = 0; i < 10; i++) {
        cards.push_back(Card("Pink", 5000));
        cards.push_back(Card("Sky", 10000));
        cards.push_back(Card("Purple", 15000));
        cards.push_back(Card("Green", 20000));
    }
// ?????????????? 6 ??
        for (int i = 0; i < 6; i++) {
        cards.push_back(Card("Silver", 25000));
    } //????????????? 4 ??
        for (int i = 0; i < 4; i++) {
        cards.push_back(Card("Gold", 50000));
    }
}

class Player {
    public:
    vector<Card> hand;
    vector<Card> mycard;
    void draw(Deck &d)
    {
//???????????? deck ??????? push??????????????? deck ???????
    hand.push_back(d.cards.back());
//?????????????????? deck ???
    d.cards.pop_back();
}
//????????? drop card demo(???????????????????????)
void drop()
{
    cout << "Your hand:" << endl;
    for (int i = 0; i < hand.size() ; i++)
    {
        cout << "["<< i+1 <<"]" << hand[i].money << " " << hand[i].color << endl;
    }
    int select;
    cout << "Select number u want to drop. 1 - " << hand.size()<< endl;
    cin >> select;
    
// ???????? ??? ????????????????????????????????? ??????????
    if (select < 1 || select > hand.size())
    {
        cout << "incorrect please input number correctly. 1 - " << hand.size() <<endl;
        drop();
        return;
    }
//???????????????????????
    hand.erase(hand.begin() + select -1); //why -1???

    }
    
void botdrop(){
	int select = rand()%5;
	hand.erase(hand.begin() + select -1);
}
//????????
vector<Card> match_card(int s1, int s2){
        if(hand[s1-1].money==hand[s2-1].money){
            mycard.push_back(hand[s1-1]);
            mycard.push_back(hand[s2-1]);
             hand.erase(hand.begin()+s1-1);
   			 hand.erase(hand.begin()+s2-1);
        }

     /*for (int i = 0; i < mycard.size() ; i++)
    {
        //cout << "["<< i+1 <<"]" << hand[i].money << " " << hand[i].color << endl;
        cout << "[" << i+1 << "]" << mycard[i].money<< " " << mycard[i].color << endl;
}**/
    return mycard;
}
vector<Card> botmatch_card(int s1, int s2){
        if(hand[s1].money==hand[s2].money){
            mycard.push_back(hand[s1]);
            mycard.push_back(hand[s2]);
              hand.erase(hand.begin()+s1);
   			  hand.erase(hand.begin()+s2);
        }
     /*for (int i = 0; i < mycard.size() ; i++)
    {
        //cout << "["<< i+1 <<"]" << hand[i].money << " " << hand[i].color << endl;
        cout << "[" << i+1 << "]" << mycard[i].money<< " " << mycard[i].color << endl;
}**/
    return mycard;
}
 
/*int stealCard(vector<int> mycard){
    int a;
    for(unsigned int i = 0; i < 5; i++){
        if(mycard[sizeof(mycard)] == hand[i].money){
            a = hand[i].money;
            hand.erase(hand.begin()+i);
        }
    }
    cout << a;
    return a;
}*/
void stealCard(Player &b, Player &p,vector<Card> &mid,bool &s){
  for (int i = 0; i < p.hand.size(); i++)
  {
    if (b.mycard[b.mycard.size()-1].money==p.hand[i].money)
    {
      mid.push_back(p.hand[i]);
      //cout << mid[i].money << endl;
      mid.push_back(p.hand[i]);
     // cout << mid[i].money;
      mid.push_back(p.hand[i]);
      p.hand.erase(p.hand.begin()+i);
      b.mycard.pop_back();
       b.mycard.pop_back();
      s = true;
    }
    /*for(int i =0; i<p.hand.size(); i++){
				cout << mid[i].money << " " << mid[i].color << endl;
			}*/
    //mid <3???>
   // p1.stealCard(b,p1);
    
  }
}

void botstealCard(Player &b, Player &p,vector<Card> &mid,bool &s){
  for (int i = 0; i < p.hand.size(); i++)
  {
    if (p.mycard[mycard.size()-1].money==b.hand[i].money)
    {
      mid.push_back(b.hand[i]);
      b.hand.erase(b.hand.begin()+i);
      mid.push_back(p.mycard[sizeof(mycard)-1]);
      p.mycard.pop_back();
      mid.push_back(p.mycard[sizeof(mycard)-1]);
      p.mycard.pop_back();
      s =1;
    }
    //mid <3???>
   // p1.stealCard(b,p1);
    
  }
}

/*void protect(Player &p,vector<Card> mid){
    for(unsigned int k = 0; k < p.hand.size() ; k++){
    cout << "["<< k+1 << "] " << p.hand[k].money<< '\n';
    }
    int choose;
    cin >> choose;
        if(p.hand[choose-1]==mid.end()){
            mid.push_back(p.hand[choose-1]);
            p.hand.erase(p.hand.begin()+choose-1);
       }else if(p.hand[choose-1] == 25000){
            mid.push_back(p.hand[choose-1]);
            p.hand.erase(p.hand.begin()+choose-1);
       }else if(p.hand.[choose-1] == 50000){
            mid.push_back(p.hand[choose-1]);
            p.hand.erase(p.hand.begin()+choose-1);
        }
    for(unsigned int j = 0; j < p.hand.size() ; j++){
        cout << "["<< j+1 << "] " <<  p.hand[j].money <<p.hand[j].color<< '\n';
    }
}*/



};

void total_score(Player &a, Player &b) {
	int sum_p = 0;
	int sum_b = 0;
		for (int i = 0; i < a.mycard.size(); i++) {
 // ?????????????????????????
		sum_p += a.mycard[i].money;
		}
		
		for (int j = 0; j < b.mycard.size(); j++) {
 // ?????????????????????????
		sum_b += b.mycard[j].money;
		}
		if(sum_p>sum_b) {
				cout << "*******************************************************\n";
				for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
				cout << "*           YOU WIN!!! " << "YORE SCORE IS " << sum_p <<             "           *\n";
				for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
				cout << "*******************************************************\n";
		}
		else if(sum_p==sum_b){
		        cout << "*******************************************************\n";
				for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
				cout << "*                      TIE!!!                         *\n";
				for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
				cout << "*******************************************************\n";
		}
	    else{
		        cout << "*******************************************************\n";
				for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
				cout << "*                   YOU LOSE!!!                       *\n";
				for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
				cout << "*******************************************************\n";
		}
	
}


int main()
{   
    start();
    string password;
    do{
        cout << "\nPLEASE INPUT 'accept' TO START -> ";
        cin >> password;
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    }while(password!="accept");
    
	vector <Card> mid;
    //????? Deck d ????????????? class Deck
    Deck d;
    //????? Player p1 ????????????? class player
    Player p1,bot;
    srand(time(0));
    //??????
    d.shuffle();
    //???????5??
    bool first = true,stealp = false,stealb = false,protectp = false, protectb =false;
    for (int i = 0; i < 5; i++)
    {
       p1.draw(d);
       bot.draw(d);
       
    }
    //????????????? + ???????? draw drop
    int turn_count = 1;
    while (true)
    {
      //???????
      int select1,select2;
      int s1 = 0;
      int s2 = 0;
      if(turn_count%2 == 1){
      cout << "Your hand:" << endl;
      for (int i = 0; i < p1.hand.size(); i++) 
        {
          cout << "["<< i+1 <<"]" << p1.hand[i].money << " " << p1.hand[i].color << endl; 
        }
      string b;
      //???????? draw ???
      cout << "Do you want to draw?(y or n)"<< endl;
      cin >> b;
      //???draw 
      if (b == "y")
       {
        p1.draw(d);
        //??????? 5 ?? ???????? drop
        if (p1.hand.size() > 5)
        {
            cout << "You have 6 cards drop 1 of your cards"<<endl;
            p1.drop();
        }
        
       }
      //?????? draw
      else if (b == "n")
      {
        string c;
        cout << "Do you want to match / steal / protect / exit ?(m or s or p or e)" << endl;
        cin >> c;
        if(c == "m"){
            cout << "Please choose card that you want match ";
            cin >> select1 >> select2;
            p1.match_card(select1,select2);
            if(p1.hand.size()<5){
                p1.draw(d);
                p1.draw(d);
            }
           cout << "MY CARD\n"; 
           for(int j=0; j<p1.mycard.size(); j++){
            	cout << "["<< j+1 <<"]" << p1.mycard[j].money << " " << p1.mycard[j].color << endl; 
			}
        }
        else if(c == "s"){
        	if(bot.mycard.size()!=0){
        		p1.stealCard(bot,p1,mid,stealp);
            	if (stealp == true)
           		{
					if(protectb == 0){
	           		p1.mycard.push_back(mid[mid.size()-1]);
		            mid.pop_back();
		            p1.mycard.push_back(mid[mid.size()-1]);
		            mid.pop_back();
		            p1.mycard.push_back(mid[mid.size()-1]);
		            mid.pop_back();
		            stealp = 0;
					   }
					else{
					bot.mycard.push_back(mid[mid.size()-1]);
	            	mid.pop_back();
	            	bot.mycard.push_back(mid[mid.size()-1]);
	            	mid.pop_back();
	            	bot.mycard.push_back(mid[mid.size()-1]);
	            	mid.pop_back();
	            	protectb = 0;
	            	stealp = 0;
					}
            
     			}
		        if(p1.hand.size()<5){
						p1.draw(d);
				}
				cout << "MY CARD\n";
          		for(int j=0; j<p1.mycard.size(); j++){
            	cout << "["<< j+1 <<"]" << p1.mycard[j].money << " " << p1.mycard[j].color << endl; 
			}
        		
			}
			else
			{ 
				cout << "YOU CAN NOT STEAL. PLEASE CHOOSE AGAIN IN THE NEXT ROUND.\n";
				
			
			}
        	

        }
        else if(c == "p"){
        	protectp = 1;
		}
        else if(c=="e"){
        	cout << "-------------------------\n";
        	for(int i = 0; i<p1.mycard.size(); i++){
        		
        		cout << "["<< i+1 <<"]" << p1.mycard[i].money << " " << p1.mycard[i].color << endl; 
			}
			cout << "-------------------------\n";
			for(int j = 0; j<bot.mycard.size(); j++){
        		cout << "["<< j+1 <<"]" << bot.mycard[j].money << " " << bot.mycard[j].color << endl; 
			}
			cout << "-------------------------\n";
        	total_score(p1,bot);
        	
        	cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
        	
            break;
            //p1.draw(d);
            //p1.drop();
           // p1.protect(5000);
        }
        else{
            cout <<"Please choose again.\n";
        }
        //break;
      }
      //??????????????????
      else
      {
        cout << "Please input y or n"<< endl ;
      }
     
     }
     else if(turn_count%2 == 0){
     	int temp = rand()%4;
     	if(p1.mycard.size()!=0){
	 	for(int k=0; k<bot.hand.size(); k++){
	 	
	 			if(bot.hand[k].money == bot.hand[k+1].money){
	 			s1 = k;
	 			s2 = k+1;
				}
				else if(bot.hand[k].money == bot.hand[k+2].money){
	 			s1 = k;
	 			s2 = k+2;
				}
				else if(bot.hand[k].money == bot.hand[k+3].money){
	 			s1 = k;
	 			s2 = k+3;
				}
				else if(bot.hand[k].money == bot.hand[k+4].money){
	 			s1 = k;
	 			s2 = k+4;
				}
				 
			}
		if((((s1 != 0 && s2 != 0 )|| (s1 == 0 && s2 != 0) ) && first == true )|| (first == false && (temp == 2 || temp == 3 ))){
			 cout << "BOTCARD\n";
			 bot.botmatch_card(s1,s2);
			 cout << "------------------Botmatched------------------\n";
			 if(d.cards.size()!=0){
			 	bot.draw(d);
			 	bot.draw(d);
			 }else{
			 	total_score(p1,bot);
			 }
		for(int p=0; p<bot.mycard.size(); p++){
            	cout << "["<< p+1 <<"]" << bot.mycard[p].money << " " << bot.mycard[p].color  << endl; 
				}
			first = false;
		    }
	    }
		/*if(first == false){
			if(temp == 1){
			cout << "botsteal\n";
			if(p1.hand.size()!=0) bot.stealCard(p1,bot, mid,stealb);
		    if(bot.hand.size()<5) bot.draw(d);
		}
		else if(temp == 0){
			cout << "Botprotect";
			protectb = 1;
		}
		}*/
		else if(temp == 1 && first == false){
			cout << "------------------Botsteal------------------\n";
			if(p1.hand.size()!=0) bot.stealCard(p1,bot, mid,stealb);
		    if(bot.hand.size()<5) bot.draw(d);
		    cout << "BOTCARD\n";
		    for(int p=0; p<bot.mycard.size(); p++){
            	cout << "["<< p+1 <<"]" << bot.mycard[p].money << " " << bot.mycard[p].color  << endl; 
				}
		}
		else if(first == false && temp == 0){
			//cout << "-----------------Botprotect-----------------\n";
			protectb = 1;
			cout << "BOTCARD\n";
			for(int p=0; p<bot.mycard.size(); p++){
            	cout << "["<< p+1 <<"]" << bot.mycard[p].money << " " << bot.mycard[p].color  << endl; 
				}
		}
		else {
        	bot.draw(d);
        	bot.botdrop();
        	cout << "BOTCARD\n";
        	for(int j=0; j<bot.hand.size(); j++){
            	cout << "["<< j+1 <<"]" << bot.hand[j].money << " " << bot.hand[j].color << endl; 
			}
			first = false;
		}
	//cout << temp << endl;
		
     }
     if(stealp == 1 && protectb == 0){
     	p1.mycard.push_back(mid[0]);
     	p1.mycard.push_back(mid[1]);
     	p1.mycard.push_back(mid[2]);
     	stealp = 0;
	 }else if(stealb == 1 && protectp == 0){
	 	bot.mycard.push_back(mid[0]);
     	bot.mycard.push_back(mid[1]);
     	bot.mycard.push_back(mid[2]);
     	stealb = 0;
	 }else if(stealb == 1 && protectp == 1){
	 	p1.mycard.push_back(mid[0]);
     	p1.mycard.push_back(mid[1]);
     	p1.mycard.push_back(mid[2]);
     	stealb = 0;
     	protectp = 0;
	 }else if(stealp == 1 && protectb == 1){
     	bot.mycard.push_back(mid[0]);
    	bot.mycard.push_back(mid[1]);
     	bot.mycard.push_back(mid[2]);
     	stealp = 0;
     	protectb = 0;
	 }
	 
     mid.clear();
	 turn_count++;
     cout << "\nRound : " << turn_count<<endl;
     //cout << "first : "<< first << endl;
     if(d.cards.size()==0){
      	total_score(p1,bot);
     	break;
     
	 }
	 
  }

     
 }

