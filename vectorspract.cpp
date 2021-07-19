#include <iostream>   // ostream
#include <vector>

#define SIZE 10

using namespace std;


void print_all(vector <long unsigned int> & v) { for(unsigned int i=0; i<v.size(); i++) cout << v[i] << " ";}
void print(vector <long unsigned int> & v, unsigned int st, unsigned int end) { for(unsigned int i=st; i<=end; i++) cout << v[i] << " ";}


/*
  Partitions the vector between indices start and end.
  Uses the first element as pivot.
  Precondition:
  Postcondition: All elements smaller than or equal to the pivot
    will be moved the left part of the vector, while the others to
    the right. The pivot is moved to a position  between the left
    and right parts.
  Returns: The position of the pivot after it has been moved.
*/
int partition(vector<long unsigned int> & a, int start, int end) {
  unsigned int pivot = a[end];
  unsigned int i = start - 1 ;
  unsigned int j;
//   unsigned int from_right = end;
  unsigned int tmp;
  
  //cout << "Vector entering partition:";
  //print (a,start,end);
  //cout << endl;
  for(j=start;j<end-1;j++)
  {
      if(a[j]<=pivot)
      {
          i++;
          tmp = a[i];
          a[i] = a[j];
          a[j] = a[i];
      }
  }
  tmp = a[i+1];
  a[i+1] = a[end];
  a[end] = tmp;
  return i+1;
  
}

/*
  Recursive QS function. Base case is an empty vector.
  Precondition:
  Postcondition: The vector that was passed as parameter will be
    sorted in ascending order.
*/
void quickSort(vector <long unsigned int> & a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
  }
}

/*
  Fills a vector of size SIZE with randomly generated numbers.
  Then QuickSorts it.
*/

int main() {  
  vector<long unsigned int> a(SIZE);
    int elem;
//   srand ( time(NULL) );
  long unsigned int n;
  // cin >> n;
  for (long unsigned int i=0; i<SIZE; i++) 
    {   
        cin >> elem;
        a[i] = elem;
    }
    

  quickSort(a, 0, SIZE-1);

  print_all (a);
  return 0;
}