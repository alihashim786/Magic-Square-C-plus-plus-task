#include <iostream>
#include <iomanip>
using namespace std;

int** generateMagicSquare(int dimension) {
int** magicsquare=new int*[dimension];  //dynamically allocating a memory to a 2D array pointer vaiable using new operator
 
	 for(int i=0;i<dimension;i++){
	   magicsquare[i]=new int[dimension];   //now alloacted a memory for each row
	   for (int j = 0; j<dimension; j++)
            {
            magicsquare[i][j] = 0;      //must set it to 0 because when we use it for larger values it will give us garbage value without doing that
            }
	 }

//I will set row to 0 and col to 2 so that my frst input should be place on the upper row and in the middle column
int row=0;
int col=dimension/2;
for(int input=1;input<=(dimension*dimension);input++){
   magicsquare[row][col]=input;
   int new_rcell=(row+dimension-1)%dimension;     //this will calculate the row where the next input should be
   int new_ccell=(col+1)%dimension;              //this will calculate the column where the next input should be

//now we will check that whether the next cell where the next input input should is empty or occupied if it that is occupied then we will change the position of next cell just below to the previous one.
if (magicsquare[new_rcell][new_ccell]){  
//now I will change the position to just below the previous input.
new_rcell= (row+1)%dimension;            
      new_ccell=col;
      }
 
 //done this beacuse on next itteration I have indexes named row and column and it wil update the values in it.
row=new_rcell;
col=new_ccell;
}


return magicsquare;    //All my created magic square will be returned to where it has been called

//Now as i have returned my magic square from where it has been called so now I will deallocate a memory which was assigned to magicsquare 2D pointer
for (int i=0;i<dimension;i++)
    {
        delete[] magicsquare[i];
    }
    delete[] magicsquare;

}             


						int main(){
						int dimension;
									  cout<<"Enter the dimension of the Magic Square:\n";
									  cin>>dimension;
									  
									  do{
									  if((dimension==1)||(dimension%2==0)){
									  cout<<"Magic Square should be of an odd order (eg: 3*3 , 5*5 etc)\nEnter dimension again:\n";
									  cin>>dimension;
									  }
									 }while((dimension==1)||(dimension%2==0));
						  
						 
						  int** square = generateMagicSquare(dimension);

						cout<<"Magic Square of "<<dimension<<"*"<<dimension<<" order is:\n\n";
						    for(int i=0;i<dimension;i++){
						    for(int j=0;j<dimension;j++){
						     cout<<setw(4)<<square[i][j]<<" ";
						     }
						     cout<<endl;
						     }
						cout<<endl;



						  // Calculate expected sum
						  int expectedSum = (dimension * (dimension * dimension + 1)) / 2;
						  cout<<"expected Sum is : "<<expectedSum<<endl;
						  // Check sum of each row
						  for (int i = 0; i < dimension; i++) {
						    int rowSum = 0;
						    for (int j = 0; j < dimension; j++) {
						      rowSum += square[i][j];
						    }
						    cout<<"Sum of row "<<i+1<<" is "<<rowSum<<endl;
						  }

						  // Check sum of each column
						  for (int j = 0; j < dimension; j++) {
						    int colSum = 0;
						    for (int i = 0; i < dimension; i++) {
						      colSum += square[i][j];
						    }
						    cout<<"Sum of column "<<j+1<<" is "<<colSum<<endl;
						  }

						  // Check sum of diagonals
						  int diag1Sum = 0;
						  int diag2Sum = 0;
						  for (int i = 0; i < dimension; i++) {
						    diag1Sum += square[i][i];
						    diag2Sum += square[i][dimension - i - 1];
						  }
						 cout<<"Sum of diAGONAL 1 is "<<diag1Sum<<endl;
						 cout<<"Sum of diAGONAL 2 is "<<diag2Sum<<endl;
						  // Deallocate memory
						  for (int i = 0; i < dimension; i++) {
						    delete[] square[i];
						  }
						  delete[] square;

						}


		
