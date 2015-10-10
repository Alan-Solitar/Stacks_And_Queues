#include "queue.h"
#include "stack.h"
#include <iostream>
#include <fstream>
#include <vector>

void printVector(std::vector<int> v);
void findValley(std::vector<int> v); //Function for the second problem
int main()
{
	
//This is code reverses the queue using the stack - simple and fairly trivial. 
//The next problem which calculates the valley for a list of prices is more interesting. 
	
    std::cout<<"\nUse the Stack to Reverse the Queue\n"<<std::endl;
    std::vector<int> prices; //This vector will be used in problem 3
    int temp;
    std::ifstream reader("values.txt"); //read in values from text file
    queue<int> q; //will enqueue values from the text file
    stack<int> s; //will push dequeued values form the qeueue
    while (reader >> temp)
    {
	prices.push_back(temp); //filling up this now for convenience
	q.enqueue(temp); 
    }
    reader.close();
	std::cout<<"Here is the Queue:"<<std::endl;
    q.display(); //this is the queue full of values
    

    int qSize = q.size(); //size of queue
    for (int i = 0; i < qSize; i++) 
    {
        s.push(q.dequeue()); //push dequed values into stack
        
    }
    int sSize = s.size(); //stack size
    for (int i = 0; i < qSize; i++) 
    {
        q.enqueue(s.pop()); //enqueue reversed values into queue.
    }
	std::cout<<"Here is the Reversed Queue:"<<std::endl;
    q.display(); //Print the reversed qeueue.
//end of reversal
    
   
//Code to find the valley of a list of n prices.  Valley[0] is 0 by definition.
//
	std::cout<<"Calculate the valley for a set of n prices\n"<<std::endl;
	std::cout<<"The list of prices is:"<<std::endl;
	printVector(prices);
	findValley(prices); //This function is defined below main
}

void findValley(std::vector<int> v)
{
	
	int n = v.size();
	stack<int> index; //creates a stack that will hold indexes of values
	int* valley = new int[n]; //dynamic array to hold valley
	valley[0] = 0; //by definition  
	int value_index = 0; //initialize
	//starting from day n
	for (int i = n - 1; i >= 0; i--) 
	{

		if (i == 0)
		{	
		
			while (!index.isEmpty())
			{
				//must pop all indexes that remain at the end
				value_index = index.pop();

				if (v[value_index] < v[0]) //a valley was found
				{
					valley[value_index] = value_index - i;
					
				}
				else
				{
					valley[value_index] = 0; //no equal or higher price found
				}
			}
		}
		else
		{
			index.push(i); //push index
			int current = v[i - 1]; //look at the (i-1)th value
			if (v[index.top()] <= current)
			{
				do
				{
					value_index = index.pop();
					valley[value_index] = value_index - i;
					
				} while (!index.isEmpty() && v[index.top()] <= current);
				
			}
			else
			{
			//Do Nothing
			}
		}
	
	}

	std::cout<<"Here is the Valley:"<<std::endl;
	for (int i = 0; i < n; i++)
	{	
		std::cout << valley[i] << " ";
	}
	std::cout<<"\n"<<std::endl;
	delete[] valley;
}

void printVector(std::vector<int> v)
{
	int size = v.size();
	for(int i =0;i<size;i++)
	{
		std::cout<< v[i]<<" ";
	}
	std::cout<<"\n"<<std::endl;
}
	
