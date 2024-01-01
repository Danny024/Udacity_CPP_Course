#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
struct Soul {
    private :
        vector <string> will_;
        vector <string> emotions_;
        vector <string>  mind_;
    
    public :
      // Getters or an accessor 
      vector <string> Thoughts () const;
      vector <string> Feelings ()const;
      vector <string> Decisions () const; 

      //Setters or a mutator
      void Thinks (string thoughts);
      void Feels (string feelings);
      void Decides (string decisions);

      static void Discerner (Soul Human);

      // 

};


// Function Implementation
vector <string> Soul::Thoughts () const{
    return mind_;
}

vector <string> Soul::Feelings () const{
    return emotions_;
}

vector<string> Soul::Decisions () const{
    return will_;
}

void Soul::Thinks (string thoughts){
    mind_.emplace_back (thoughts);

}

void Soul::Feels (string feelings){
    emotions_.emplace_back (feelings);
}

void Soul::Decides (string decisions){

    will_.emplace_back(decisions);

}

void Soul::Discerner (Soul Human){
    for (const string &thoughts : Human.mind_ ){
        cout << thoughts<<endl;
    }

    for (const string &emotions : Human.emotions_){
        cout << emotions << endl;
    }

    for (const string &decisions : Human.will_){
        cout << decisions << endl;
    }
}

int main (){
    Soul Adam;
    Adam.Thinks ("I thought God said we should not eat of the Tree of knowledge of good and evil. ");
    Adam.Feels ("I love my wife so much I can't afford to lose her ");
    Adam.Decides ("Let me obey my wife and eat of the tree ");

    // Get Adam thoughts
    vector <string> thought_memory;
    vector <string> emotion_memory;
    vector <string> decision_memory;

    thought_memory.emplace_back("I thought God said we should not eat of the Tree of knowledge of good and evil. ");
    emotion_memory.emplace_back("I love my wife so much I can't afford to lose her ");
    decision_memory.emplace_back("Let me obey my wife and eat of the tree ");
     
     // Test 
    assert (Adam.Thoughts()==thought_memory);
    assert (Adam.Feelings()== emotion_memory );
    assert (Adam.Decisions()==decision_memory);

    // Discern Adam
    Soul::Discerner (Adam);
    

}