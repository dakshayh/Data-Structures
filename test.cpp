#include<iostream>
#include "sq.h"
int menu()
{
        int opt;
        cout << "\nEnter your required option...\n1.INSERT IN QUE 1\n2.INSERT IN QUE 2\n3.DELETE IN QUE 1\n4.DELETE IN QUE 2\n5.DISPLAY QUE 1\n6.DISPLAY QUE 2\n.7.MERGE QUES";
        cin >> opt;
        return opt;
}

int main()
{
	try
	{
        aqueue<int> aq(5),aq2(5),aq1,aq3(6);
        int opt, pos, x;

           while(1)
                {
                        opt = menu();

                        switch(opt)
                        {
                                case 1:
                                cout << "\nEnter the element to insert:";
                                cin >> x;
                                aq.insert(x);
                                cout << endl << x << " is inserted into queue 1." << endl;
                                break;

                                case 2:
                                cout << "\nEnter the element to insert:";
                                cin >> x;
                                aq2.insert(x);
                                cout << endl << x << " is inserted into queue 2." << endl;
                                break;

                                case 3:
                                cout << "\nThe element " << aq.del() << " is deleted from queue 1." << endl;
                                break;

                                case 4:
                                cout << "\nThe element " << aq2.del() << " is deleted from queue 2." << endl;
                                break;

                                case 5:
                                cout << "\nThe elements in the 1st queue are ";
                                aq.display();
                                break;

                                case 6:
                                cout << "\nThe elements in the 2nd queue are ";
                                aq2.display();
                                break;

								case 7:
								cout<<"\n Mergeing the two queues: \n";
								aq1=aq.mergeQueues(aq2);

                        }
                }
        }

        catch(const char *s)
        {
                cout << "\nException caught : " << s << "\nProgram terminated..";
        }
        return 0;
}

