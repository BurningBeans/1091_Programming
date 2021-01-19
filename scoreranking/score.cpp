#include "iostream"
#include "iomanip"
#include "fstream"
#include "string"
#include "vector"
#include "algorithm"
void ssort(std::vector<int> &v, std::vector<std::string> &s, std::vector<std::string> &n)
{
    if (v.size()<1)
    {
        //pass
    }
    else
    {
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = i+1; j < v.size(); j++)
            {
                if(v[i] < v[j])
                {
                    std::swap(v[i], v[j]);
                    std::swap(s[i], s[j]);
                    std::swap(n[i], n[j]);
                }
            }
        }
    }
}
int main(int argc, char **)
{
    std::string filename("score.txt");
    //std::cin >> filename;

    std::fstream fptr(filename,std::ios::in);
    if (!fptr)
    {
        std::cerr << "File could not be opened!";
        exit(1);
    }
    std::string id;
    std::vector<std::string> idV;
    std::string name;
    std::vector<std::string> nameV;
    int score;
    std::vector<int> scoreV;
    while(fptr >> id >> name >> score)
    {
        idV.push_back(id);
        nameV.push_back(name);
        scoreV.push_back(score);
    }
    fptr.close();
    ssort(scoreV, idV, nameV);
    for(int i=0; i < scoreV.size(); i++)
    {
        if(scoreV[i] == scoreV[i-1])
            //std::cout << "Rank " << std::setw(2) << i << " :";
            std::cout << "Rank    :";
        else
            std::cout << "Rank " << std::setw(2) << i+1 << " :";
        std::cout << std::setw(7) << idV[i] << ' ' << std::setw(10) << nameV[i] << ' ' << std::setw(3) << scoreV[i] << std::endl;
    }
    std::ofstream ofptr("ranked_score.txt");
    for(int i = 0; i < scoreV.size(); i ++)
    {
                if(scoreV[i] == scoreV[i-1])
            //std::cout << "Rank " << std::setw(2) << i << " :";
            ofptr << "Rank    :";
        else
            ofptr << "Rank " << std::setw(2) << i+1 << " :";
        ofptr << std::setw(7) << idV[i] << ' ' << std::setw(10) << nameV[i] << ' ' << std::setw(3) << scoreV[i] << std::endl;
    }
    system("pause");
}