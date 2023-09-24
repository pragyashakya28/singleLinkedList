#include <iostream>
#include <string.h>
#include "array.cpp"
#include "linkedlist.cpp"
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

long getTime() {
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec*1000000 + start.tv_usec;
}

long getMemUsage() {
	struct rusage myusage;
	getrusage(RUSAGE_SELF, &myusage);
	return myusage.ru_maxrss;
}
 
void performanceAnalysis(string dataStructureType, int insertionProbability, int iterations) {
	if(dataStructureType == "Array") {
		Array<int> arr;
	
		long start = getTime();
		for(int i=0; i<iterations; i++) {
			int randomNumber = rand() % 100; // generate random number between 0 and 99 to insert in array
		
			if(randomNumber < insertionProbability) {
				arr.insertElement(randomNumber);
			} else {
				arr.deleteElementFromEnd();
			}
		}
		long end = getTime();
		cout << "Total time : " << end - start << "\n";
		long usage = getMemUsage();
		cout << "Space used : " << usage << "\n";
	} 
	
	if(dataStructureType == "LinkedList") {
		LinkedList<int> ll;
		
		long start = getTime();
		for(int i=0; i<iterations; i++) {
			int randomNumber = rand() % 100; // generate random number between 0 and 9 to insert in array
		
			if(randomNumber < insertionProbability) {
				ll.insertNode(randomNumber);
			} else {
				ll.deleteNodeFromEnd();
			}
		}
		long end = getTime();
		cout << "Total time : " << end - start << "\n";
		long usage = getMemUsage();
		cout << "Space used : " << usage << "\n";
	}
}

int main(int argc, char* argv[]) {
	if(argc == 4) {
		string dataStructureType = argv[1];
		int insertionProbability = atoi(argv[2]);
		int iterations = atoi(argv[3]);
		
		performanceAnalysis(dataStructureType, insertionProbability, iterations);
	}
	
	
	return 0;
}
