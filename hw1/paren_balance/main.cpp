#include <iostream>
#include <string>

using namespace std;

// Implement below
bool are_paren_balanced(string& expression);

// We have suggested a helper method, but feel free to write whatever you see fit
bool are_paren_balanced1( string& expression, int i, char expected_closing);

// Do not change this method
int main(int argc, char* argv[]) {

    // Check if an expression has been passed to the program
    if (argc != 2) {
        cerr << "error: expected expression to check!" << endl;
        return -1;
    }

    // The second argument is the expression string in the format specified and
    // promised in the assignment page. You do not need to do any error checking
    // except for checking the parentheses.
    string expression(argv[1]);
    if (are_paren_balanced(expression)) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }
    return 0;
}

// Some notes:
// - This method must be implemented recursively.
// - When debugging, make sure to output to cerr rather than cout. This will
//   prevent any leftover debug statements from confusing the automated
//   grading and will make sure output is guaranteed to be written to the
//   terminal in case your program crashes.
bool are_paren_balanced(string& expression) {
    // TODO: your code here
    int i=0;
    int size=expression.length();
    if(expression[i]=='('){
       return are_paren_balanced1(expression, i, ')');
    }
    else if(expression[i]=='['){
    	cout << "strange3" << endl;
        return are_paren_balanced1(expression, i, ']');
        	
    }
    else if (expression[i]=='\0'){
    	cout << "strange4" << endl;
    	cout << "end3" << endl;
        return true;
    }

    else{
    	cout << "strange5" << endl;
    	cout << "end4" << endl;
        return are_paren_balanced1(expression, i, '(');
    }



}

// Add any additional function implementations here.
//
// If you want to use the suggested helper method, you'll have to write its
// definition here.

bool are_paren_balanced1(string& expression, int i, char expected_closing){
	int cntb=0;
	int cntp=0;
	cout << endl << expression << endl << "expression[i]: " << expression[i] << endl;
	cout << "expected closing:" << expected_closing << endl;


	if (expression[i]=='\0' && expected_closing=='\0'){
		cout << "super true" << endl;
		return true;
	}
    else if( expression[i]=='\0'){
    	
        if(expected_closing==')' || expected_closing ==']') {
        	cout << "did you go here?" << endl;
            return false;
        }
        else if(expected_closing=='(' || expected_closing =='[') {
        	cout << "did you go here?" << endl;
            return false;
        }
        else{
            return true;
        }
    }
    //else if (expression[i]==']'){
    //}

        //return are_paren_balanced1(expression, i+1, expected_closing);

   else if (expression[i]==']' && expected_closing==')'){
   	return false;
   }
   else if (expression[i]==')' && expected_closing==']'){
   	return false;
   }
    
   else if (expression[i]==')'){
   		cout << "DEBUG HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << endl;
        if(expected_closing==')'){
    		expression[i]='*';
    		return true;
    	}
    	else if (expected_closing=='\0'){
    		return false;
    	
    	}
    	else{
    		return are_paren_balanced1(expression, i+1, expected_closing);
    	}

    }

        

    
    else if (expression[i]==']'){

    	if(expected_closing==']'){
    		expression[i]='*';
    		return are_paren_balanced1(expression, i+1, '\0');
    	}
    	else if (expected_closing=='\0'){
    		return false;
    	}
    	else{
    		return are_paren_balanced1(expression, i+1, expected_closing);
    	}
    }


 

    
    
    else if (expression[i]=='('){
    	cout << "enter2"<< endl;
    	expression[i]='*';
    	//expected_closing=')';
    	cntp++;

    	if(!are_paren_balanced1(expression, i+1, ')')){
    		cout << "if passed 2" << endl;
        	if(cntp==1 && expression[expression.length()-1]==')'){
        		cout << "true passed here" << endl;
        		cout << "weird expres[i]: " << expression[i] << endl;
        		return true;
        	}
        	else {
        		cout << "false" << endl;
        		return false;
        	}
        }

        else
        	return true;
    }
        

        
    else if (expression[i]=='['){
    	cout << "enter3"<< endl;
    	expression[i]='*';
        expected_closing=']';
		cntb++;
		//if(are_paren_balanced1(expression, i+1, ']')){
			//cout << "decount here" << endl;
			//cntb--;
		//}

        if(!are_paren_balanced1(expression, i+1, ']')){
        	if(cntb==1 && expression[expression.length()-1]==']'){
        		cout << "true passed here" << endl;
        		cout << "weird expres[i]: " << expression[i] << endl;
        		return true;
        	}
        	else {
        		cout << "false" << endl;
        		return false;
        	}
        }

        
		
        else{
        	cout << "went here" << endl;
        	return true;
        }
    }


        
    
    



    else if(expression[i]==expected_closing){
    	if(expected_closing==')'){
    		
    	}
    	else if (expected_closing==']'){
    	}
    	cout << "yeet" << endl;
        return are_paren_balanced1(expression, i+1, expected_closing);
    }

    else{
    	cout << "yeeeeeet" << endl;
        return are_paren_balanced1(expression, i+1, expected_closing);
    }

}