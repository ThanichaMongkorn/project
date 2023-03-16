#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;
	

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
        }

   hand.erase(hand.begin()+s1-1);
   hand.erase(hand.begin()+s2-1);

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
        }

   hand.erase(hand.begin()+s1);
   hand.erase(hand.begin()+s2);

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
    //mid <3ค่า>
   // p1.stealCard(b,p1);
    
  }
}

void botstealCard(Player &b, Player &p,vector<Card> mid,bool &s){
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
    //mid <3ค่า>
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

int total_score(Player &a) {
	int sum = 0;
		for (int i = 0; i < a.mycard.size() - 1; i += 2) {
 // ?????????????????????????
		sum += a.mycard[i].money;
		}

	return sum;
}

};

void game_finish(int a,int b){
	if(a > b){
		cout << "Player wins" << a;
	}
	else if (b > a) cout << "Bot wins" << b;
	else cout << "Tie";
}


int main()
{   
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
      cout << "do you want to draw?(y or n)"<< endl;
      cin >> b;
      //???draw 
      if (b == "y")
       {
        p1.draw(d);
        //??????? 5 ?? ???????? drop
        if (p1.hand.size() > 5)
        {
            cout << "you have 6 cards drop 1 of your cards"<<endl;
            p1.drop();
        }
        
       }
      //?????? draw
      else if (b == "n")
      {
        string c;
        cout << "Do you want to match or steal?(m or s or e)" << endl;
        cin >> c;
        if(c == "m"){
            cout << "please choose card that you want match ";
            cin >> select1 >> select2;
            p1.match_card(select1,select2);
            if(p1.hand.size()<5){
                p1.draw(d);
                p1.draw(d);
            }
           cout << "my card\n";
           for(int j=0; j<p1.mycard.size(); j++){
            	cout << "["<< j+1 <<"]" << p1.mycard[j].money << " " << p1.mycard[j].color << endl; 
			}
        }
        else if(c == "s"){
        	p1.stealCard(bot,p1,mid,stealp);
            if (stealp == true)
            {
                    p1.mycard.push_back(mid[mid.size()-1]);
                    mid.pop_back();
                     p1.mycard.push_back(mid[mid.size()-1]);
                    mid.pop_back();
                     p1.mycard.push_back(mid[mid.size()-1]);
                    mid.pop_back();
              
                

            }
            
        	//bot.protect(bot,mid);
        	if(p1.hand.size()<5){
				p1.draw(d);
		
			}
			//	p1.mycard.push_back(mid[mid.size()-1]);
			//	mid.pop_back();
			/*if(p1.mycard[p1.mycard.size()-1].money==mid[mid.size()-1].money){
				do{
					p1.mycard.push_back(mid[mid.size()-1]);
					mid.pop_back();
				}
				while(p1.mycard[p1.mycard.size()-1].money==mid[mid.size()-1].money);
			}*/

			cout << "my card\n";
           for(int j=0; j<p1.mycard.size(); j++){
            	cout << "["<< j+1 <<"]" << p1.mycard[j].money << " " << p1.mycard[j].color << endl; 
			}
        }
        else if(c == "p"){
        	protectp = 1;
		}
        else if(c=="e"){
            //break;
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
     	int temp = rand()%2;
     		
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
		if((s1 != 0 && s2 != 0 )|| (s1 == 0 && s2 != 0)){
			 cout << "botCard\n";
			 bot.botmatch_card(s1,s2);
			 cout << "botMatched\n";
			 bot.draw(d);
			 bot.draw(d);
		for(int p=0; p<bot.mycard.size(); p++){
            	cout << "["<< p+1 <<"]" << bot.mycard[p].money << " " << bot.mycard[p].color  << endl; 
				}
			first == false;
		}
		else if(stealb == true && first == false){
			cout << "botsteal\n";
			if(p1.hand.size()!=0) bot.stealCard(p1,bot, mid,stealb);
		    if(bot.hand.size()<5) bot.draw(d);
		}
		else if(first == false && temp == 0){
			protectb = 1;
		}
		else {
        	bot.draw(d);
        	bot.botdrop();
        	for(int j=0; j<bot.hand.size(); j++){
            	cout << "["<< j+1 <<"]" << bot.hand[j].money << " " << bot.hand[j].color << endl; 
			}
			first == false;
		}

		
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
     cout << turn_count<<endl;
     if(d.cards.size()==0){
     	int p_score = p1.total_score(p1);
     	int b_score = bot.total_score(bot);
     	
     	game_finish(p_score,b_score);
	 }
	 
  }



 	
 
   /*  while (true)
     {
        cout << "Your hand:" << endl;
        for (int i = 0; i < p1.hand.size(); i++) 
        {
          cout << "["<< i+1 <<"]" << p1.hand[i].money << " " << p1.hand[i].color << endl; 
        }
        string c;
        cout << "Do you want to match or steal?(m or s or e)" << endl;
        cin >> c;
        if(c == "m"){
            int select1,select2;
            cout << "please choose card that you want match ";
            cin >> select1 >> select2;
            p1.match_card(select1,select2);
            if(p1.hand.size()<5){
                p1.draw(d);
                p1.draw(d);
            }
            cout << "my card\n";
           for(int j=0; j<p1.mycard.size()-1; j++){
            	cout << "["<< j+1 <<"]" << p1.mycard[j].money << " " << p1.mycard[j].color << " " << p1.mycard[j+1].money << " " << p1.mycard[j+1].color << endl; 
			}
        }
        else if(c == "s"){
           int choose2;
            cout << "please choose card that you want steal";
            cin >> choose2;
            p1.stealCard(vector<int> mycard);
            p1.protect(5000);

        }
        else if(c=="e"){
            break;
            //p1.draw(d);
            //p1.drop();
           // p1.protect(5000);
        }
        else{
            cout <<"Please choose again.\n";
        }
        //break;
     }*/
     
 }
