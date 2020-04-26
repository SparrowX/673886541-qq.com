#include <iostream>
#include <fstream>
#include <unordered_set>
#include<algorithm>
using std::cin;
using std::cout;            using std::endl;
using std::string;          using std::unordered_set;

string read_file(){
    cout<<"Input file name:";
    string filename; cin>>filename;
    std::ifstream iss(filename);
    string result; string tmp;
    while(getline(iss, tmp)) result+=tmp;
    return result;
}
unordered_set<string> findWikiLinks(const string& page_html){
    unordered_set<string> result;
    auto it = page_html.begin();
    string start_string = "<a href=\"/wiki/";
    while(1){
      it = std::search(it,page_html.end(), start_string.begin(), start_string.end());
      if(it == page_html.end()) break;
      auto end_it = std::find(it+15,page_html.end(),'"');
      //end_it = std::find(end_it,page_html.end(),'"');
      string link = page_html.substr(it - page_html.begin()+15, end_it - (it+15));
      if(std::all_of(link.begin(), link.end(), [](char i){return (i != '#') && (i != ':');})){
          result.insert(link);
      }
      it++;
    }
    return result;
}
int main() {
	
    /* TODO: Write code here! */
    string page_html = read_file();
    unordered_set<string> ans = findWikiLinks(page_html);
    cout<<ans.size()<<endl;
    for(string s : ans) cout<<s<<endl;
    /* Note if your file reading isn't working, please follow the
     * steps posted on the front page of the CS106L website. Essentially
     * go to the projects tab on the panel on the left, and in the run
     * section, uncheck the "Run in terminal" box and re-check it. This
     * should fix things.
     */
}
