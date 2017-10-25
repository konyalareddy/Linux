/*Copyright (c)  2017 Ramakrishna Reddy
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include <iostream>
#include <unistd.h>
#include <csignal>
using namespace std;

class ProcessFactory{
        private:
        int children;
        public:
        ProcessFactory(int babies){
                children = babies;
        }
        void ChainOfBabies(){
                int generations=0;
                cout << "Below is the Chain Reproduction System"<<endl;
                cout << "I am Mother, my ID : "<<getpid()<<endl;
                while(generations++ < children) {       
                        pid_t pid = fork();
                        if(pid < 0){
                                cout<<"Reproduction problem\n"<<endl;
				exit(1);
                        }
                        else if(pid == 0) {
                                cout<<"I am new born: "<<generations<<" : my ID\t"<<getpid()<<"\tMy Mother ID :\t"<<getppid()<<endl;   
                        }
                        else{
                                // My life time is over
                                break ;
                        }
                }

        }
	pid_t produceChild(){
		pid_t pid;
		if((pid = fork()) < 0){
			cout<<"Reproduction problem"<<endl;
			exit(1);
		}
		return pid;
	}
		
        void BinaryCuties(int level){
		if(level > children){
			return;
		}
		if(produceChild() ==0 || produceChild() == 0)
			BinaryCuties(level + 1);
		else{
		/*	int a=0;
			while(a++ != 10)
			{
				char data[200];
				system("nc 192.168.1.140 3000");
				
			}*/
			cout<<"I am New Bee: ID:\t"<<getpid()<<"\t my Mother ID :\t"<<getppid()<<endl;
		}
		
        }

};

int main(int argc, char *argv[])
{
        if(argc != 2){
                cout << "usage: "<<argv[0] << " <no of childs >"<<endl;
                return -1;
        }
        else{
         cout << "Thank you process factory  got your input"<<endl;
         ProcessFactory factory(atoi(argv[1]));
//         factory.ChainOfBabies();
//	 sleep(1);
         factory.BinaryCuties(1);
        }
        sleep(1);
return 0;
}
