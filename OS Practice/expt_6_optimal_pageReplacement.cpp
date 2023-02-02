// ! Optimal Page Replacement Algorithm : Replace the page which is not used in the longest dimension of time in future
#include <iostream>
#include <vector>
using namespace std;

vector<int> pages,frames;
int noOfHits = 0,noOfFrames,noOfPages; 

bool isPagePresent(int page){
    for(int i = 0; i < frames.size();i++){
        if (frames[i] == page) 
        {
        		return true;
		}
		
    }
    return false;
}
void displayFrames(int noOfFrames){
    int i=0;
    for(i = 0; i < frames.size();i++){
        cout << frames[i] << "      " ;
    }
    cout << endl;
    
}
int findPageToReplace(int noOfPages,int noOfFrames,int startIndex){
    int result = -1,farthest = startIndex,j;
    for(int i=0;i<=frames.size();i++){
        for(j=startIndex;j<noOfPages;j++){
            if (frames[i] == pages[j]){
                if (j > farthest){
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == noOfPages)
            return i;
    }
    if (result == -1)
        return 0;
    return result;
}
void optimalPageReplacement(int noOfPages,int noOfFrames)
{  
    noOfHits = 0;

    for(int i=0;i<noOfPages;i++){
        displayFrames(noOfFrames);
        if (isPagePresent(pages[i]))
		{
            noOfHits++;
            continue;
        }

        if (frames.size() < noOfFrames)
            frames.push_back(pages[i]);
        
        else{
            // Find page to be replaced
            int index = findPageToReplace(noOfPages,noOfFrames,i+1);
            frames[index] = pages[i];
        }
    }
}
int main()
{
    int page;

    cout << "Enter the number of frames:";
    cin >> noOfFrames;

    cout << "Enter the number of pages:";
    cin >> noOfPages;

    cout << "Enter pages" << endl;
    for(int i = 0; i < noOfPages; i++){
        cin >> page;
        pages.push_back(page);
    }

    cout << endl;
    for(int i=0;i<noOfFrames;i++){
        cout <<  "F" << i+1 << "    " ;
    }
    optimalPageReplacement(noOfPages,noOfFrames);


    cout << endl;
    cout << "No of page hits = " << noOfHits << endl;
    cout << "No of page faults = " << noOfPages - noOfHits << endl;
    cout << "Hit ratio = " << noOfHits / (noOfPages*1.0) << endl;

    return 0;
}
