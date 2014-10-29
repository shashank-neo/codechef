#include<iostream>
#include<map>
using namespace std;
int main() {
	int n,m;
	while(cin>>n){
		cin>>m;
		map<string, string> chefVsCountry;
		map<string, int> countryScore;
		map<string, int> chefScore;
		string bestChef, bestCont;
		int bestChefScore = -1, bestContScore = -1;
		for(int i=0;i<n;i++) {
			string temp1, temp2;
			cin>>temp1>>temp2;
			chefVsCountry[temp1] = temp2;
			chefScore[temp1] = 0;
			countryScore[temp2] = 0;
		}
		string subject;
		for(int i=0;i<m;i++) {
			cin>>subject;
			string cntry = chefVsCountry[subject];
			chefScore[subject]+= 1;
			countryScore[cntry]+=1;
			if(chefScore[subject] > bestChefScore) {
				bestChefScore = chefScore[subject];
				bestChef = subject;
			} 
			if(chefScore[subject] == bestChefScore && (subject < bestChef)) {
				bestChefScore = chefScore[subject];
				bestChef = subject;
			} 

			if(countryScore[cntry] > bestContScore) {
				bestContScore = countryScore[cntry];
				bestCont = cntry;
			}
			if(countryScore[cntry] == bestContScore && (cntry < bestCont)) {
				bestContScore = countryScore[cntry];
				bestCont = cntry;
			}

		}
		cout<<bestCont<<"\n"<<bestChef<<"\n";
	}

}