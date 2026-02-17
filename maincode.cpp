#include<bits/stdc++.h>
using namespace std;

//function for finding similarity using cosine similarity formula
double cosine_similarity(vector<int>&a, vector<int>&b){
    
    if (a.size() != b.size() || b.empty()) {
        return 0.0;
    }

    double dot=0;
    //dot means dot product

    for(int i=0; i<a.size(); i++){
        dot+=a[i]*b[i];
    } 

    double mag_a=0, mag_b=0;
    //mag_a means magnitude of a, similarly for b

    for(int i=0; i<a.size(); i++){
        mag_a+=a[i]*a[i];
        mag_b+=b[i]*b[i];
    }

    if(mag_a==0 || mag_b==0){
        return 0;
    }

    return dot/(sqrt(mag_a)*sqrt(mag_b));

}

int main(){

    //list of movies:
    vector<string>movies= {
        "Interstellar",
        "Inception",
        "The BFG", 
        "Dune", 
        "The Martian", 
        "Dune Part2", 
        "Iron Man"
    };

    int total_movies=movies.size();

    //initializing map with entries that include ratings of all the movies from all the friends
    unordered_map<string, vector<int>>friends ={
        {"Aprajita", {5,4,0,5,4,1,1}}, 
        {"Bhavishya", {2,1,0,3,5,2,3}}, 
        {"Tanisha", {1,5,4,5,3,5,4}}, 
        {"Isha", {5,2,1,3,5,3,4}}
    };
    
    //takings user's ratings for all the movies as input 
    cout<<endl<<"Enter user's ratings in all the movies (0 if not watched) : ";
    vector<int>user_ratings;
    int a;
    for(int i=0; i<total_movies; i++){
        cout<<movies[i]<<" : ";
        cin>>a;
        user_ratings.push_back(a);
    }

    double similarity;
    double most_similar=-1;
    string best_match;

    //calculating similarity of user's ratings with friends' ratings in the same movies.
    for(auto x: friends){
        similarity= cosine_similarity(x.second, user_ratings);
        if(similarity>most_similar){
            most_similar=similarity;
            best_match=x.first;
        }
    }
    cout<<endl<<"Most similar friend: "<<best_match<<" "<<"with a similarity score: "<<most_similar;

    //get ratings of the most similar friend:
    vector<int>similar_friend_ratings=friends[best_match];

    int best_rating=-1;
    string recommended_movie;
    for(int i=0; i<total_movies; i++){
        if(user_ratings[i]==0){
            if(similar_friend_ratings[i]>best_rating){
                best_rating=similar_friend_ratings[i];
                recommended_movie=movies[i];
            }
        }
    }

    //if the user has already seen all the movies
    if(recommended_movie==""){
        cout<<endl<<"No movie recommendation"<<endl;
    }
    else{
        cout<<endl<<"Recommended movie: "<<recommended_movie<<" (Rated "<<best_rating<<" by "<<best_match<<")";
    }
    return 0;

}