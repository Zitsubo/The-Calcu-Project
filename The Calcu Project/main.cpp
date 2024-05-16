#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include<algorithm>
class thefourhorsemen // + - * / is what i mean
{
	double num;
public:
	// These are the binary opeartors.
	thefourhorsemen operator*(thefourhorsemen ob)
	{
		thefourhorsemen temp;
		temp.num = num * ob.num;
		return temp;
	}
	thefourhorsemen operator-(thefourhorsemen ob)
	{
		thefourhorsemen temp;
		temp.num = num - ob.num;
		return temp;
	}
	thefourhorsemen operator+(thefourhorsemen ob)
	{
		thefourhorsemen temp;
		temp.num = num + ob.num;
		return temp;
	}
	thefourhorsemen operator/(thefourhorsemen ob)
	{
		thefourhorsemen temp;
		temp.num = num / ob.num;
		return temp;
	}
	thefourhorsemen operator^(thefourhorsemen ob)
	{
		thefourhorsemen temp;
		temp.num = pow(num , ob.num );
		return temp;
	}


	//THe below opearators are unary oparators like ++ --
	thefourhorsemen operator++()
	{
		num++;
		return *this;
	}
	thefourhorsemen operator--()
	{
		num--;
		return *this;
	}



	void setnum(double n) // The setnum functions like this and the one below are requaired for setting numbers obviesly.
	{
		num = n;
	}
	void setnum(thefourhorsemen n)
	{
		num = n.num;
	}


	void display() // To show numbers
	{
		std::cout<<num;
	}


	double getnum() // To retreive numbers if needed
	{
		return num;
	}

	friend thefourhorsemen SWITCHER(thefourhorsemen X, thefourhorsemen KNIGHT, char x); // friend function to do the math where the first two objects are numbers and the x char iss the op.
};

thefourhorsemen SWITCHER(thefourhorsemen X, thefourhorsemen KNIGHT, char x )  //it does the math by switch and the char x is for operator.
{
	switch(x)
	{
		{
		case '+':
			X.num = X.num + KNIGHT.num;
			break;
		}
		{
		case '-':
			X.num = X.num - KNIGHT.num;
			break;
		}
		{
		case '*':
			X.num = X.num * KNIGHT.num;
			break;
		}
		{
		case '/':
			X.num = X.num / KNIGHT.num;
			break;
		}
		{
		case '^':
			X.num = pow(X.num , KNIGHT.num);
			break;
		}

	}
	return X;
}
void fixer(std::string &input) // to fix wrong input like 3 + 3-4+5 -> 3 + 3 - 4 + 5 // also to remove additionl space like 2   + 2 -> 2 + 2 but i didn't implent it yet.
{
	// this section us to erase spaces like 2   +         4 -> 2 + 4
	for(int i = 0; i < input.size()-1; i++)
	{

		if(i == 0)
		{
			if(isdigit(input.at(0)) && input.at(1) == '+' || input.at(1) == '-' || input.at(1) == '*' || input.at(1) == '/' || input.at(1) == '^')
			{
				input.insert(1 , " ");
			}
			else if(isdigit(input.at(1)) && input.at(0) == '+' || input.at(0) == '-' || input.at(0) == '*' || input.at(0) == '/' || input.at(0) == '^')
			{
				input.insert(1 , " ");
			}
		}
		if (std::isspace(input.at(i)))
		{
			int O=0;
			for(int j = i; j < input.size()-1; j++)
			{
				if(std::isdigit(input.at(i)))
					break;
				else if(std::isspace(input.at(i+1)))
					input.erase(i , O+1);
				O = 0;
			}
		}
		if (std::isspace(input.at(i+1)))
		{
			int O=0;
			for(int j = i; j < input.size()-1; j++)
			{
				if(std::isdigit(input.at(i)))
					break;
				else if(std::isspace(input.at(i)))
					input.erase(i , O+1);
				O = 0;

			}




			//idk what's this but it fix spaces too
			/*if(std::isdigit(input.at(i)))
			 *       {
			 *           if(i == 0)
			 *               continue;                       it breaks the program.
			 *           int O = 0;
			 *           if(std::isspace(input.at(i-1)) || std::isspace(input.at(i-2)))
			 *           {
			 *               i-=1;
			 *               input.erase(i , O+1 );
			 }
			 }
			 */


			// This section is to fix wrong input like 3+ 4-5 -> 3 + 4 + 5.
		}
		if(input.length() >=2)
		{
			if(std::isdigit(input.at(i) && (input.at(i+1) == '+' || input.at(i+1) == '-' || input.at(i+1) == '*' || input.at(i+1) == '/' || input.at(i+1) == '^' )))
				input.insert(i+1 , " ");
			if(std::isdigit(input.at(i)) && !std::isspace(input.at(i + 1))  )
			{
				if(std::isdigit(input.at(i+1)) || input.at(i+1) == '.' || input.at(i+1) == ')' || input.at(i-1) == '(')
					continue;
				input.insert(i+1, " ");
			}
			if(std::isdigit(input.at(i+1)) && !std::isspace(input.at(i)))
			{
				if(std::isdigit(input.at(i)) || input.at(i) == '.' || input.at(i+1) == ')' || input.at(i-1) == '(' )
					continue;
				input.insert(i+1, " ");

			}

			// back to erasing.
			if(input.at(i) == '(' && std::isspace(input.at(i+1)))
				input.erase(i+1 , 1);
			if(input.length() < 4)
				if(input.at(i) == '-' && isspace(input.at(i+1)) && input.at(i+2) == '-')
				{
					input.erase(i+1 , 1);
				}
		}
		if(isspace(input.at(0)))
			input.erase(0 , 1);



	}
}


int ischar(std::string phrase) //this my own function to check for charectar input.
{
	if(phrase == "fact" || phrase == "Fact")
	{
		tt:
		return 1;
	}
	for(int i = 0; i < phrase.length(); i++)
	{
		if(phrase.at(i) == '(' || phrase.at(i) == ')')
			goto tt;

		if((phrase.at(i) >= 'a' && phrase.at(i) <= 'z') || (phrase.at(i) >= 'A' && phrase.at(i) <= 'Z'))
		{
			return 10;
			break;
		}

	}
}
double sec (double n)
{
	double cosine = cos(n);
	return (1 / cosine);
}
double csc (double n)
{
	return (1 / sin(n));
}
double cot (double n)
{
	return (1 / tan(n));
}
double fact (double x)
{
	double num = x;
	for (int i = 1; i <x; i++)
	{
		num = num * i;
	}
	return num;
}
void sciencechecker( std::string &input) // to check for fact , sin , cos , etc.
{ int n = input.length();
	size_t fact_position = input.find("fact");
	size_t sin_position = input.find("sin");
	size_t cos_position = input.find("cos");
	size_t tan_position = input.find("tan");
	size_t sec_position = input.find("sec");
	size_t csc_position = input.find("csc");
	size_t cot_position = input.find("cot");
	size_t asin_position = input.find("asin");
	size_t acos_position = input.find("acos");
	size_t atan_position = input.find("atan");
	size_t sinh_position = input.find("sinh");
	size_t cosh_position = input.find("cosh");
	size_t tanh_position = input.find("tanh");
	size_t asc_arranging_position = input.find("asc");
	size_t desc_arranging_position = input.find("desc");
	size_t max_position = input.find("max");
	size_t min_position = input.find("min");

	std::string inputX;



	//checking for fact input... like fact(7).
	while(fact_position != std::string::npos)
	{
		fact_position = input.find("fact");
		double num;
		size_t fact_start , End;
		fact_start =  input.find('(' , fact_position);
		if(fact_start != std::string::npos)
		{
			End = input.find(')' , fact_start);
		if(End != std::string::npos)
		{
			num = std::stod(input.substr(fact_start+1 , End - fact_start - 1));
			num = fact(num);
			input.replace(fact_position , End - fact_position + 1 ,std::to_string(num));
		}
		}


		fact_position = input.find("fact", fact_position + 1);
	}

	// checking for sin input... like sin(5).
	while(sin_position != std::string::npos)
	{
		sin_position = input.find("sin");
		double num;
		size_t sin_start , sin_end;
		sin_start = input.find('(');
		if(sin_start != std::string::npos)
		{
			sin_end = input.find(')' , sin_start);
		if(sin_end  != std::string::npos)
		{
			num = std::stod(input.substr(sin_start+1 , sin_end - sin_start - 1));
			double angle = num * M_PI / 180;
			num = sin(angle);
			input.replace(sin_position , sin_end - sin_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next sin
		sin_position = input.find("sin" , sin_position + 1);
	}
	while(cos_position != std::string::npos)
	{
		cos_position = input.find("cos");
		inputX = input;
		double num;
		size_t cos_start , cos_end;
		cos_start = input.find('(');
		if(cos_start != std::string::npos)
		{
			cos_end = input.find(')' , cos_start);
		if(cos_end  != std::string::npos)
		{
			num = std::stod(input.substr(cos_start+1 , cos_end - cos_start - 1));
			double angle = num * M_PI / 180;
			num = cos(angle);
			input.replace(cos_position , cos_end - cos_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next cos
		cos_position = input.find("cos" , cos_position + 1);
	}

	// checking for tan input... like tan(120)
	while(tan_position != std::string::npos)
	{
		tan_position = input.find("tan");
		inputX = input;
		double num;
		size_t tan_start , tan_end;
		tan_start = input.find('(');
		if(tan_start != std::string::npos)
		{
			tan_end = input.find(')' , tan_start);
		if(tan_end  != std::string::npos)
		{
			num = std::stod(input.substr(tan_start+1 , tan_end - tan_start - 1));
			double angle = num * M_PI / 180;
			num = tan(angle);
			input.replace(tan_position , tan_end - tan_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next tan
		tan_position = input.find("tan" , tan_position + 1);
	}

	//checking for sec input... like sec(21).
	while(sec_position != std::string::npos)
	{
		sec_position = input.find("sec");
		inputX = input;
		double num;
		size_t sec_start , sec_end;
		sec_start = input.find('(');
		if(sec_start != std::string::npos)
		{
			sec_end = input.find(')' , sec_start);
		if(sec_end  != std::string::npos)
		{
			num = std::stod(input.substr(sec_start+1 , sec_end - sec_start - 1));
			double angle = num * M_PI / 180;
			num = sec(angle);
			input.replace(sec_position , sec_end - sec_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next sec
		sec_position = input.find("sec" , sec_position + 1);
	}




	//checking for csc input... like csc(372).
	while(csc_position != std::string::npos)
	{
		csc_position = input.find("csc");
		inputX = input;
		double num;
		size_t csc_start , csc_end;
		csc_start = input.find('(');
		if(csc_start != std::string::npos)
		{
			csc_end = input.find(')' , csc_start);
		if(csc_end  != std::string::npos)
		{
			num = std::stod(input.substr(csc_start+1 , csc_end - csc_start - 1));
			double angle = num * M_PI / 180;
			num = csc(angle);
			input.replace(csc_position , csc_end - csc_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next csc
		csc_position = input.find("csc" , csc_position + 1);
	}

	//checking for cot input... like cot(90).
	while(cot_position != std::string::npos)
	{
		cot_position = input.find("cot");
		inputX = input;
		double num;
		size_t cot_start , cot_end;
		cot_start = input.find('(');
		if(cot_start != std::string::npos)
		{
			cot_end = input.find(')' , cot_start);
		if(cot_end  != std::string::npos)
		{
			num = std::stod(input.substr(cot_start+1 , cot_end - cot_start - 1));
			double angle = num * M_PI / 180;
			num = cot(angle);
			input.replace(cot_position , cot_end - cot_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next cot
		cot_position = input.find("cot" , cot_position + 1);
	}

	//checking for asin or sin inverse to be precise... like asin(5)
	while(asin_position != std::string::npos)
	{
		asin_position = input.find("asin");
		inputX = input;
		double num;
		size_t asin_start , asin_end;
		asin_start = input.find('(');
		if(asin_start != std::string::npos)
		{
			asin_end = input.find(')' , asin_start);
		if(asin_end  != std::string::npos)
		{
			num = std::stod(input.substr(asin_start+1 , asin_end - asin_start - 1));
			double angle = num * M_PI / 180;
			num = asin(angle);
			input.replace(asin_position , asin_end - asin_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next asin
		asin_position = input.find("asin" , asin_position + 1);
	}

	//checking for acos input... like acos(578).
	while(acos_position != std::string::npos)
	{
		acos_position = input.find("acos");
		inputX = input;
		double num;
		size_t acos_start , acos_end;
		acos_start = input.find('(');
		if(acos_start != std::string::npos)
		{
			acos_end = input.find(')' , acos_start);
		if(acos_end  != std::string::npos)
		{
			num = std::stod(input.substr(acos_start+1 , acos_end - acos_start - 1));
			double angle = num * M_PI / 180;
			num = acos(angle);
			input.replace(acos_position , acos_end - acos_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next acos
		acos_position = input.find("acos" , acos_position + 1);
	}

	//checking for atan input... like atan(233).
	while(atan_position != std::string::npos)
	{
		atan_position = input.find("atan");
		inputX = input;
		double num;
		size_t atan_start , atan_end;
		atan_start = input.find('(');
		if(atan_start != std::string::npos)
		{
			atan_end = input.find(')' , atan_start);
		if(atan_end  != std::string::npos)
		{
			num = std::stod(input.substr(atan_start+1 , atan_end - atan_start - 1));
			double angle = num * M_PI / 180;
			num = atan(angle);
			input.replace(atan_position , atan_end - atan_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next atan
		atan_position = input.find("atan" , atan_position + 1);
	}


	// checking for sinh...
	while(sinh_position != std::string::npos)
	{
		sinh_position = input.find("sinh");
		inputX = input;
		double num;
		size_t sinh_start , sinh_end;
		sinh_start = input.find('(');
		if(sinh_start != std::string::npos)
		{
			sinh_end = input.find(')' , sinh_start);
		if(sinh_end  != std::string::npos)
		{
			num = std::stod(input.substr(sinh_start+1 , sinh_end - sinh_start - 1));
			double angle = num * M_PI / 180;
			num = sinh(angle);
			input.replace(sinh_position , sinh_end - sinh_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next sinh
		sinh_position = input.find("sinh" , sinh_position + 1);
	}

	//checking for cosh...
	while(cosh_position != std::string::npos)
	{
		cosh_position = input.find("cosh");
		inputX = input;
		double num;
		size_t cosh_start , cosh_end;
		cosh_start = input.find('(');
		if(cosh_start != std::string::npos)
		{
			cosh_end = input.find(')' , cosh_start);
		if(cosh_end  != std::string::npos)
		{
			num = std::stod(input.substr(cosh_start+1 , cosh_end - cosh_start - 1));
			double angle = num * M_PI / 180;
			num = cosh(angle);
			input.replace(cosh_position , cosh_end - cosh_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next cosh
		cosh_position = input.find("cosh" , cosh_position + 1);
	}

	//checking for tanh...
	while(tanh_position != std::string::npos)
	{
		tanh_position = input.find("tanh");
		inputX = input;
		double num;
		size_t tanh_start , tanh_end;
		tanh_start = input.find('(');
		if(tanh_start != std::string::npos)
		{
			tanh_end = input.find(')' , tanh_start);
		if(tanh_end  != std::string::npos)
		{
			num = std::stod(input.substr(tanh_start+1 , tanh_end - tanh_start - 1));
			double angle = num * M_PI / 180;
			num = tanh(angle);
			input.replace(tanh_position , tanh_end - tanh_position + 1 , std::to_string(num));
		}
		}
		// to reset the position for the next tanh
		tanh_position = input.find("tanh" , tanh_position + 1);
	}
	while(asc_arranging_position != std::string::npos)
	{
		asc_arranging_position = input.find("asc");
		size_t asc_start , asc_end;
		asc_start = input.find('(' , asc_arranging_position);
		if(asc_start != std::string::npos)
		{
			asc_end = input.find(')' , asc_start);
		if(asc_end !=std::string::npos)
		{
			std::string substring = input.substr(asc_start+1 , asc_end - asc_start - 1);
			fixer(substring);
			std::istringstream iss(substring);
			double num;
			std::vector<double> numbers;
			while(iss >> num)
			{
				numbers.push_back(num);
			}
			//sorting...
			std::sort(numbers.begin() , numbers.end());
			std::stringstream ss;
			for(double number : numbers)
			{
				ss << number << " ";
			}
			std::string sortedstring = ss.str();
			input.replace(asc_start+1 , asc_end - asc_start-1 , sortedstring);
			asc_arranging_position = asc_end;
		}
		}
		asc_arranging_position = input.find("asc" , asc_arranging_position+1);
	}


	//decsendery thing.
	while(desc_arranging_position != std::string::npos)
	{
		desc_arranging_position = input.find("desc");
		size_t desc_start , desc_end;
		desc_start = input.find('(' , desc_arranging_position);
		if(desc_start != std::string::npos)
		{
			desc_end = input.find(')' , desc_start);
		if(desc_end !=std::string::npos)
		{
			std::string substring = input.substr(desc_start+1 , desc_end - desc_start - 1);
			fixer(substring);
			std::istringstream iss(substring);
			double num;
			std::vector<double> numbers;
			while(iss >> num)
			{
				numbers.push_back(num);
			}
			//sorting...
			std::sort(numbers.begin() , numbers.end() , std::greater<double>());
			std::stringstream ss;
			for(double number : numbers)
			{
				ss << number << " ";
			}
			std::string sortedstring = ss.str();
			input.replace(desc_start+1 , desc_end - desc_start-1 , sortedstring);
			desc_arranging_position = desc_end;
		}
		}
		desc_arranging_position = input.find("desc" , desc_arranging_position+1);
	}
	//checking for max...
	while(max_position != std::string::npos)
	{
		max_position = input.find("max");
		inputX = input;
		double num;
		size_t max_start , max_end;
		max_start = input.find('(');
		if(max_start != std::string::npos)
		{
			max_end = input.find(')' , max_start);
		if(max_end  != std::string::npos)
		{
			std::string substring = input.substr(max_start+1 , max_end - max_start - 1);
			fixer(substring);
			std::istringstream iss(substring);
			double num;
			std::vector<double> numbers;
			while(iss >> num)
			{
				numbers.push_back(num);
			}
			double maxnumber = 0;
			for(int i = 0; i < numbers.size(); i++)
			{
				if(maxnumber<numbers[i])
					maxnumber = numbers[i];
			}
			std::string nummmm = std::to_string(maxnumber);
			input.replace(max_position , max_end - max_position+1,nummmm);
		}
		}
		// to reset the position for the next max
		max_position = input.find("max" , max_position + 1);
	}
	//Checking for min...
	while(min_position != std::string::npos)
	{
		min_position = input.find("min");
		inputX = input;
		double num;
		size_t min_start , min_end;
		min_start = input.find('(');
		if(min_start != std::string::npos)
		{
			min_end = input.find(')' , min_start);
		if(min_end  != std::string::npos)
		{
			std::string substring = input.substr(min_start+1 , min_end - min_start - 1);
			fixer(substring);
			std::istringstream iss(substring);
			double num;
			std::vector<double> numbers;
			while(iss >> num)
			{
				numbers.push_back(num);
			}
			double minnumber = 10000000;
			for(int i = 0; i < numbers.size(); i++)
			{
				if(minnumber>numbers[i])
					minnumber = numbers[i];
			}
			std::string nummmm = std::to_string(minnumber);
			input.replace(min_position , min_end - min_position+1,nummmm);
		}
		}
		// to reset the position for the next min
		min_position = input.find("min" , min_position + 1);
	}

}


void timechecker() // a function to check the time so it greet you with a prober greeting.
{
	int midnight = 0, dusk = 5, sunrise = 6, morning = 7, afternoon = 12, sunset = 18, evening = 19;

	time_t currenttime = time(0); // here we got the whole time into a variable.



	struct tm * now = localtime(&currenttime); // here we transferd the data into an object of structrue so we could use them.

	int currenthour = now->tm_hour; // we got the current hour to check with our variables above.

	if(currenthour >= midnight && currenthour < dusk)
		std::cout<< "Its quite dark right now, what's on your mind?";
	else if(currenthour >= dusk && currenthour < sunrise)
	{
		std::cout<< "Did you finish your prayers? yes or no? ";
		std::string c;
		std::cin>>c;
		if(c == "yes")
			std::cout<< "Then you may use my services"<<std::endl;
		if(c == "no")
			std::cout<< "YOU SHOULD HAVE!"<<std::endl;
	}
	if(currenthour > sunrise && currenthour < morning)
		std::cout<< "Ughhhh, how can i help you? "<< '\n';
	else if(currenthour >= morning && currenthour < afternoon)
		std::cout<< "Good morning, how could i assist you in this beautiful day? "<< '\n';
	else if(currenthour >= afternoon && currenthour <sunset)
		std::cout<< "Is it a sunny noon?, it would be nice to see by myself.\nYou could say menu"<<std::endl;
	else if(currenthour > sunset && currenthour < evening)
		std::cout<< "Usually in this time i'm smoking but looks like you require my help "<< '\n';
	else if(currenthour >= evening)
		std::cout<< "Good eveningggg :D , how can i help you? "<< '\n';

}
int main()
{
	srand(time(NULL));
	timechecker();
	int q = 1;
	while(true)
	{
		std::string initialial_Talk; // Our main input
		std::getline(std::cin, initialial_Talk);
		for (char &c : initialial_Talk)
		{
			c = std::toupper(c);
		}
		if(initialial_Talk == "THE CALCULATOR" || initialial_Talk == "1" )
		{
			for(int p = 1 ; p<1000; p++)
			{
				if(p == 1)
				{std::cout<< "\nPlease enter what you want to evaluate \n"<<"or if you want the manuel type manuel.\n";}
				thefourhorsemen *KNIGHT;// pointer for the used numbers :D
				thefourhorsemen X; // the first number and where we store the result.
				std::string input;
				std::getline(std::cin, input); //what we are typing in the calculator.
				if(input.empty())
				{
					std::cout<< "NOTHING?"<<std::endl;
					continue;
					std::cout<< '\n';
				}
				if(input == "manuel")
				{
					system("clear");
					std::cout<< "\033[1;33m" << "GoodDay!, this is manuel for the so called CALCULATOR."<<'\n'<< "First of all, of course it does basic math like + - * / operations ";
					std::cout<< "like you could just type number + number or something idk, it accept 1.2656 or regular numbers and so and its an infinite calculator so type what you want."<< '\n';
			std::cout<< "Also there is a power usage which you can use by typing like 2 ^ 4 which translates 2 to the power of 4 which is 16."<< '\n';
			std::cout<< "Another thing is you could write ++ to plus a number with one like 99++ is 100 OR -- and it will take one from it like 99-- is 98."<< '\n';
			std::cout<< "Oh i forget, we have mathmetical stuff like sin, cos and tan."<<'\n'<<"Here's the list: "<< '\n';
			std::cout << "fact" << '\n'
			<< "sin" << '\n'
			<< "cos" << '\n'
			<< "tan" << '\n'
			<< "sec" << '\n'
			<< "csc" << '\n'
			<< "cot" << '\n'
			<< "asin ---> arc sin or sin inverse" << '\n'
			<< "acos ---> arc cos or cos inverse" << '\n'
			<< "atan ---> arc tan or tan inverse" << '\n'
			<< "sinh" << '\n'
			<< "cosh" << '\n'
			<< "tanh" << '\n'
			<< "asc" << '\n'
			<< "desc" << '\n'
			<< "max" << '\n'
			<< "min" << '\n';
			std::cout<< "To use them you need to type its name and a number in its bractes like sin(30) and so on exept for asc and desc and min and max you need to write more than one number.";
			std::cout<< "To reset the calculator to zero type 'c'."<< '\n';
			std::cout<< "To exit the calculator type exit."<< '\n';
			std::cout<< "Thats all for now :D, Bye Bye."<< "\033[0m" << '\n';
			std::cout<<  "\033[1;35m" << "THE AUTHOR:"<< "\033[0m" <<'\n';
			std::cout<<"\033[1;31m"<< "ZITSUBO | Sadiq Faisal Hammod"<< "\033[0m" << '\n';
			p=0;
			continue;
				}
				if(input.at(0) == 'c' && input.length() == 1)
				{
					system("clear");
					X.setnum(0);
					X.display();
					std::cout<< '\n';
			p=1;
			continue;
				}
				if(input == "EXIT" || input == "exit" || input == "Exit")
				{
					std::cout<< "Exiting the Calculator..."<<std::endl;
					break;
					std::cout<< '\n';
				}
				std::string inputX_for_sciencechecker;
				fixer(input);//to turn wrong input 3+3+3 -> 3 + 3 + 3
				sciencechecker(input);
				fixer(input);
				int n = input.length();
				KNIGHT = new thefourhorsemen[n];
				for (int i = 0; i < n; i ++) // to check the whole string looking for digits(better than skipping operators which lead to unwanted problems)
				{

					if (isdigit(input[i]) || input[i] == '.')
					{
						int j = i; // Start index of the number
						while ( j<n && isdigit(input[j]) || input[j] == '.')
						{
							j++;
						}
						KNIGHT[i].setnum(std::stod(input.substr(i, j - i)));
						i = j - 1; // Move the index to the end of the number
					}
				}
				if(std::isdigit(input.at(0)))
					p =1;
				if (p == 1)
				{
					X.setnum(KNIGHT[0]);
					p++;
				}
				thefourhorsemen temp;
				temp.setnum(X);
				for(int i = 0; i<input.size(); i++)
				{
					if((input[i] == '+' && input[i+1] == '+') || (input[i] == '-' && input[i+1] == '-') ) // || input[i]== '-' || input[i]=='*' || input[i] == '/' || input[i] == '^')
			{
				char x = input.at(i);
				switch (x)
				{
					case '+':
					{
						++X;
						break;
					}
					case '-':
					{
						--X;
						break;
					}
				}
				i++;
			}
			else if(input[i] == '+' || input[i]== '-' || input[i]=='*' || input[i] == '/' || input[i] == '^')
			{
				char x = input.at(i);




				X = SWITCHER(X, KNIGHT[(i+2)], x);
			}
				}

				system("clear");
				//if(!inputX_for_sciencechecker.empty())
				//std::cout<< inputX_for_sciencechecker<< '\n';
				if(p >= 3 && !std::isdigit(input.at(0)) == true)
				{
					temp.display();
				}
				if(std::isdigit(input.at(0)) || std::isdigit(input.at(1)) || input[0] == '+' || input[0] == '-')
				{
					std::cout<< " "<<input;
					std::cout<< " = ";
					X.display();
					std::cout<< '\n';
				}
				if((input.find("asc") != std::string::npos) || (input.find("desc") != std::string::npos) || (input.find("max") != std::string::npos) || (input.find("min") != std::string::npos) )
				{
					system("clear");
					std::cout<< input<< '\n';
				}

				delete []KNIGHT;
			}
		}
		else if(initialial_Talk == "EXIT")
		{
			std::cout<< "EXITING... \n";
			return 0;
		}
		else if(initialial_Talk == "MENU")
		{
			setpoint:
			std::cout<< "We have: \n 1. The calculator\n";
		}
		else
		{
			switch (q)
			{
				case 1:
				{
					std::cout<< "What?."<< '\n';
					q = (rand() % 6) + 1;
					break;
				}
				case 2:
				{
					std::cout<< "I didn't get that right."<< '\n';
					q = (rand() % 6) + 1;
					break;
				}
				case 3:
				{
					std::cout << "Hellooooo??, please check the menu."<< '\n';
					q = (rand() % 6) + 1;
					break;
				}
				case 4:
				{
					std::cout<< "JUST TYPE menu."<< '\n';
					q = (rand() % 6) + 1;
					break;
				}
				case 5:
				{
					std::cout<< "Really? here's the menu."<< '\n';
					system("pause");
					q = (rand() % 6) + 1;
					goto setpoint;
					break;
				}
				case 6:
				{
					std::cout<< "Morooooonnnnnnn!!!!!\n";
					q = (rand() % 6) + 1;
					break;
				}
			}
		}
	}
}
