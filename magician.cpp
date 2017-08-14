#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/**
 * Classe Spectator.
 */
class Spectator
{
	public:
		/**
		 * Getter age
		 * @return the member age_
		 */
		int age() const { return age_; }
		/**
		 * Getter money
		 * @return: the member money.
		 */
		int money() const { return money_; }

		/**
		 * Setter age
		 * @param: a number of int representing the amount of money.
		 * @return: if valid return asign the param to the membe variable.
		 */
		void money(int mo){
			money_ = mo;
		}

	private:
		//Members.
		int age_;
		int money_;
};

/**
 * Class Assistant.
*/ 
class Assistant
{
	public:	
		/**
		 * Getter calculatedNbr
		 */
		int calculatedNbr() const { return calculatedNbr_; }

		/**
		 * Setter calculatedNbr.
		 */
		void calculatedNbr(int age, int money){
			int calc(0);
			calc = (age*2+5) * 50 + money - 365;

			calculatedNbr_ = calc;
		}
	private:
		int calculatedNbr_;
};

/**
 * Class Magician.
 */
class Magician{
	public:
		/**
		 * Add 115 to the assistant result.
		 */
		string addOneHundredFifteen(int assistantResult){
			string finalResult;
			int addOneHundredFifteen(assistantResult + 115);

			 fundedAge_ = addOneHundredFifteen/100;
			 fundedMoney_ = addOneHundredFifteen % 100;

			return finalResult;
		}

		/**
		 * Getter for member question to ask.
		 */
		string question() const { return question_;}
		/**
		 * Getter for member age founded.
		 */
		int fundedAge() const { return fundedAge_;}
		/**
		 * Getter for member money.
		 */
		int fundedMoney() const { return fundedMoney_;}

	private:
		string question_=" \"Write down your age and the amount of money you do have in your pocket , please.\""; // The question to ask to the spectator.
		int fundedAge_;
		int fundedMoney_;
};

/**
 * Class Paper
 */
class Paper{
	public:
		/**
		 * Getter age of spectator.
		 */
		int ageOfSpectator(){ return ageOfSpectator_; }
		/**
		 * Getter money of spectator.
		 */
		int moneyOfSpectator(){ return moneyOfSpectator_; }

		/**
		 * Setter age of the spectator
		 */
		void ageOfSpectator(int age){
			 ageOfSpectator_= age;   
		}
		/**
		 * Setter money of the spectator.
		 */
		void moneyOfSpectator(int money){
			moneyOfSpectator_ = money;
		}
	private:
		int ageOfSpectator_;
		int moneyOfSpectator_;
};

/**
 * Function: Ask the user for his input. 
 * @param: the string to ask.
 */
int userInput(string question){
	int numberFromUser(0);
	bool isCorrect;
	do{
		isCorrect = true;
		cout <<"[The spectator] - I write down my "<< question <<" on the paper: ";
		if(!(cin >> numberFromUser)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Number only please ! : ";
			isCorrect = false;
		} else {
			if(numberFromUser < 1 || numberFromUser > 100){
				cout << "		- Your number is not in the good range !!!";
				cout <<"\n";
				isCorrect = false;
			}
		}
	}while(not isCorrect);
	return numberFromUser;
}
int main(){
	Magician mag; // the magician.
	cout << "[The magician] -"<< mag.question()<<"\n";//The magician ask the question.
	Paper paper;
	paper.ageOfSpectator(userInput("age"));//The spectator write down age and money.
	paper.moneyOfSpectator(userInput("money"));
	cout<<"[The spectator] - I give the paper to the assistant.\n";
	cout<<"[The Assistant] - I read the paper.\n";
	cout<<"[The Assistant] - I mentaly calculate.\n";
	Assistant as;
	as.calculatedNbr(paper.ageOfSpectator(),paper.moneyOfSpectator());
	cout << "[The assistant] - I've found "<<as.calculatedNbr()<<"\n";
	mag.addOneHundredFifteen(as.calculatedNbr()); // The magician calculate the age and money.
	cout << "[The magician] - \"hm... I see that you are "<< mag.fundedAge()<<" years old...\" \n";
	cout << "[The magician] - \"and... that you have "<< mag.fundedMoney()<<" Pounds in your pocket...\" \n";
	return 0;
}
