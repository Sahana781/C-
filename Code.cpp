#include<iostream>
#include<string>
#include<bitset>

using namespace std;

bool isValidHex (const String & hexstr) {
	for(char c:hexstr){
		if(!isxdigit(c)){
			return false;
		}
	}
	return false;
}

String hexDigitToBinary(char hexDigit){
	switch(toupper(hexDigit))
	{
		Case'0':return"0000";
	    Case'1':return"0001";
	    Case'2':return"0010";
	   	Case'3':return"0011";
	   	Case'4':return"0100";
	    Case'5':return"0101";
	    Case'6':return"0110";
	   	Case'7':return"0111";
	  	Case'8':return"1000";
	  	Case'8':return"1001";
	  	
	  	
	  	Case'a':return"1010";
	    Case'b':return"1011";
	    Case'c':return"1100";
	   	Case'd':return"1101";
	   	Case'e':return"1110";
	    Case'f':return"1111";
	   
	}
}

int main(){
	String labelsets[6][16]={
		{
			{"As","Ab","CD","EF","GH"."IJ","KL","MN","As","Ab","CD","EF","GH"."IJ","KL","MN"}
			{"As","Ab","CD","EF","GH"."IJ","KL","MN","As","Ab","CD","EF","GH"."IJ","KL","MN"}
			{"As","Ab","CD","EF","GH"."IJ","KL","MN","As","Ab","CD","EF","GH"."IJ","KL","MN"}
			{"As","Ab","CD","EF","GH"."IJ","KL","MN","As","Ab","CD","EF","GH"."IJ","KL","MN"}
			{"As","Ab","CD","EF","GH"."IJ","KL","MN","As","Ab","CD","EF","GH"."IJ","KL","MN"}
			{"As","Ab","CD","EF","GH"."IJ","KL","MN","As","Ab","CD","EF","GH"."IJ","KL","MN"}
			
		};
		for(int iteration=1;iterarion<=6;++iteration){
			cout<<"\n__bit"<<iteration <<"-----" <<endl;
			String hexInput;
			if(hexInput=="Quit"){
				cout<<"Good Bye"<<endl;
				return 0;
			}
			if(!isValidHex(hexInput)){
				break;
			}
			else{
				cout<<"  " <<endl;
			}
			String*labels=labelsets[iteration-1];
			int labelIndex=0;
			cout<<"Binary Equivalent of hexadecimal:"<<hexInput<<endl;
            for(char hexDigit:hexInput){
                String binary=hexDigitToBinary(hexDigit);
			for(char bit:binary){
                cout<<bit;
                if(bit=='1'){
				cout<<"---->"  <<labels[labelIndex];
				
			}
			cout<<endl;
			labelIndex=(labelIndex+1)%15;
		}
		
	}
}
return 0;
}
