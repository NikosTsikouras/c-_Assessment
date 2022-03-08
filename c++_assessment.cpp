#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

std::unordered_map<std::string,std::string> task_1(std::unordered_map<std::string,std::vector<std::string>> p1, std::unordered_map<std::string,std::vector<std::string>> p2)
{
    int k = 0;
    
    std::vector<std::string> male;
    std::vector<std::string> female;
    
    
    for(const auto& p : p1)
    {
        male.push_back(p.first);
    }
    
    for(const auto& p : p2)
    {
        female.push_back(p.first);
    }
    
    int n = p1[male[1]].size();
    
    for(int j = 0; j<=n-1; j++)
    {
        p2[female[j]].push_back("O");
    }
    
    
    std::unordered_map<std::string, std::string> matching;
    
    for(int i = 0; i<=n-1; i++)
    {
        matching[female[i]] = "O";
    }
    
    for(int k = 0; k<n;)
    {
        std::string X = male[k];
        for(;X!="O";)
        {
            std::string x_curr = p1[X][0];
            auto pre_ind1 = find(p2[x_curr].begin(),p2[x_curr].end(),X);
            int ind1 = std::distance(p2[x_curr].begin(),pre_ind1);
            
            auto pre_ind2 = find(p2[x_curr].begin(),p2[x_curr].end(),matching[x_curr]);
            int ind2 = std::distance(p2[x_curr].begin(),pre_ind2);

            if (ind1 < ind2)
            {
                std::string X_old = X;
                std::string X_new = matching[x_curr];
                matching[x_curr] = X;
                X = X_new;
            }
            if (X!= "O")
            {
                p1[X].erase(p1[X].begin());
            }
        }
        k = k + 1;
        
    }
    
    //We reverse the matching so that the resulting matching corresponds to the book format. Note that this step can be skipped.
    std::unordered_map <std::string, std::string> reversed_matching;
    for (const auto& p : matching)
    {
        reversed_matching[p.second] = p.first;
    }
    return reversed_matching;
}

int main()
{
    std::unordered_map<std::string,std::vector<std::string>> my_map1_5example
    {

    };
    my_map1_5example["A"]={"a","b","c","d","e"};
    my_map1_5example["B"]={"b","c","d","e","a"};
    my_map1_5example["C"]={"c","d","e","a","b"};
    my_map1_5example["D"]={"d","e","a","b","c"};
    my_map1_5example["E"]={"e","a","b","c","d"};

    std::unordered_map<std::string,std::vector<std::string>> my_map2_5example
    {

    };

    my_map2_5example["a"]={"B","C","D","E","A"};
    my_map2_5example["b"]={"C","D","E","A","B"};
    my_map2_5example["c"]={"D","E","A","B","C"};
    my_map2_5example["d"]={"E","A","B","C","D"};
    my_map2_5example["e"]={"A","B","C","D","E"};   
    
    std::unordered_map<std::string,std::string> matching = task_1(my_map1_5example,my_map2_5example);
        
    std::cout <<"The solution to the 5x5 example from the Book Stable Marriage and its Relation to Other Combinatorial Problems (Example 3, pg. 3) is:"<<std::endl;
    for(auto&p:matching)
    {
        std::cout <<p.first<<" : "<< p.second<<std::endl;
    }

    
    
    
    std::unordered_map<std::string,std::vector<std::string>> my_map1_4example
    {

    };
    my_map1_4example["A"]={"c","b","d","a"};
    my_map1_4example["B"]={"b","a","c","d"};
    my_map1_4example["C"]={"b","d","a","c"};
    my_map1_4example["D"]={"c","a","d","b"};

    std::unordered_map<std::string,std::vector<std::string>> my_map2_4example
    {

    };

    my_map2_4example["a"]={"A","B","D","C"};
    my_map2_4example["b"]={"C","A","D","B"};
    my_map2_4example["c"]={"C","B","D","A"};
    my_map2_4example["d"]={"B","A","C","D"};

    std::unordered_map<std::string,std::string> matching2 = task_1(my_map1_4example,my_map2_4example);
        
    std::cout <<"The solution to the 4x4 example from the Book Stable Marriage and its Relation to Other Combinatorial Problems (Example 1, pg. 2) is:"<<std::endl;    for(auto&p:matching2)
    {
        std::cout <<p.first<<" : "<< p.second<<std::endl;
    }

    
    return 0;
}