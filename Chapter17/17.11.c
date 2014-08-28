
/*

Imagine your solution function like a dice: 

A dice, when you throw gives only 1,2,.....21 (since you are rejecting 22,23,24,25 a.k.a rejection sampling theorem) 
So total no. of possible are 21.

No. of ways getting "1"=3 (5*1+1-5,5*2+3-5,5*3+1-1)%7

No. of ways getting "2"=3 (5*1+2-5,5*2+4-5,5*3+2-1)%7

and so on..

P(1)=3/21=1/7
P(2)=3/21=1/7 and so on...

*/

int foo(){

	//generates random integer in the range 1 to 5
}

int random(){

	int i;

	i = 5*foo() + foo() - 5;

	if(i<22){

		return i%7 + 1;
	}

	return random();
}

/*

There is no (exactly correct) solution which will run in a constant amount of time, since 1/7 is an infinite decimal in base 5. One simple solution would be to use rejection sampling, e.g.:


int i;
do
{
  i = 5 * (rand5() - 1) + rand5();  // i is now uniformly random between 1 and 25
} while(i > 21);
// i is now uniformly random between 1 and 21
return i % 7 + 1;  // result is now uniformly random between 1 and 7

*/

