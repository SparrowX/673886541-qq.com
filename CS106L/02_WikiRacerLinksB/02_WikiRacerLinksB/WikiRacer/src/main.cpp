
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h"


using std::cout;            using std::endl;
using std::string;          using std::vector;
using std::priority_queue;  using std::unordered_map;
using std::unordered_set;




/*
 * This is the function you will be implementing. It takes
 * two string representing the names of a start_page and
 * end_page and is supposed to return a ladder, represented
 * as a vector<string>, of links that can be followed from
 * start_page to get to the end_page.
 *
 * For the purposes of this algorithm, the "name" of a Wikipedia
 * page is what shows at the end of the URL when you visit that page
 * in your web browser. For ex. the name of the Stanford University
 * Wikipedia page is "Stanford_University" since the URL that shows
 * in your browser when you visit this page is:
 *
 *       https://en.wikipedia.org/wiki/Stanford_University
 */
vector<string> findWikiLadder(const string& start_page, const string& end_page) {
    // TODO: Fill in the findWikiLinks method in wikiscraper.cpp,
    //       then write this  function as per the handout.
    //
    //                Best of luck!
    WikiScraper scraper;
    auto target_set = scraper.getLinkSet(end_page);


    auto cmpFn = [&](vector<string> a, vector<string> b){
        auto page1 = scraper.getLinkSet(a.back());
        auto page2 = scraper.getLinkSet(b.back());
        int num1=0, num2=0;
        for(auto str : page1){
            if(target_set.find(str) != target_set.end()) num1++;
        }
        for(auto str : page2){
            if(target_set.find(str) != target_set.end()) num2++;
        }
        return num1 < num2;
    };
    std::priority_queue<vector<string>, vector<vector<string>>, 
            decltype (cmpFn)> ladderQueue(cmpFn);


    vector<string> ladder; ladder.push_back(start_page);
    unordered_set<string> visited;
    ladderQueue.push(ladder);
    while(!ladderQueue.empty()){
        auto front = ladderQueue.top(); ladderQueue.pop();
        auto tmp_set = scraper.getLinkSet(front.back());
        if(tmp_set.find(end_page) != tmp_set.end()){
            front.push_back(end_page);
            return front;
        }
        for(auto neighbour_page : tmp_set){
            if(visited.find(neighbour_page) == visited.end()){
                auto copy_ladder = front;
                copy_ladder.push_back(neighbour_page);
                ladderQueue.push(copy_ladder);
            }
        }
    }
    return {};
}



int main() {
    auto ladder = findWikiLadder("Fruit", "Strawberry");
    cout << endl;

    if(ladder.empty()) {
        cout << "No ladder found!" << endl;
    } else {
        cout << "Ladder found:" << endl;
        cout << "\t";

        // Print the ladder here!
    }

    return 0;
}




