#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <random>
using namespace std;

struct Countries {
    string country;
    int goalScore;
    int goalAllow;
    int penScore;
    int penAllow;
};

void createVector(vector<vector<string>> &player_list, vector<string> &row, fstream &file)
{
    string line, word = "";

    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            player_list.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";

    file.close();
}

void printVector(vector<vector<string>> &player_list, vector<string> &row){
    for (int i = 0; i < player_list.size(); i++)
    {
        for (int j = 0; j < player_list[i].size(); j++)
        {
            cout << player_list[i][j] << " ";
        }
        cout << "\n";
    }
}

double getScore(vector<vector<string>> &player_list, vector<string> &row, int whichData){
    vector<int> score;
    double stats = 0.0;
    for (int i = 0; i < player_list.size(); i++)
    {
        score.push_back(stoi(player_list[i][whichData]));
    }

    for (int i = 0; i < score.size(); i++)
        stats += score[i];
    stats = stats / score.size();
    score.empty();
    return stats;
}

float calculateSD(vector<float> const data) {
  float sum = 0.0, mean, standardDeviation = 0.0;
  int i;

  for(i = 0; i < data.size(); ++i) {
    sum += data[i];
  }

  mean = sum / data.size();

  for(i = 0; i < data.size(); ++i) {
    standardDeviation += pow(data[i] - mean, 2);
  }

  return sqrt(standardDeviation / data.size());
}

void poissonDistribution(){
    const int nrolls = 10; // number of experiments

    std::default_random_engine generator;
    std::poisson_distribution<int> distribution(4.1);

    for (int i=0; i<nrolls; ++i){
    int number = distribution(generator);
    cout<<number<<" "<<endl;
}
}

int main()
{
    vector<vector<string>> argentina, croatia, morocco, france;
    vector<string> argentinaPlayers, croatiaPlayers, moroccoPlayers, francePlayers;
    vector<vector<string>> argentina2022, croatia2022, morocco2022, france2022;
    vector<string> argentinaMatches, croatiaMatches, moroccoMatches, franceMatches;
    string line, word = "";
    /*creates vectors for the four 2022 FIFA World Cup Semi-finalists. one vector
    is used to calculate a FIFA ranking. The other vector is a list of all international
    matches played by the nation in 2022. If one of their previous matches was against
    one of the semi-finalist, it would have more weight in the calculations */
    {
    fstream argentinaFile("argentina.csv", ios::in);
    createVector(argentina, argentinaPlayers, argentinaFile);
    fstream croatiaFile("croatia.csv", ios::in);
    createVector(croatia, croatiaPlayers, croatiaFile);
    fstream moroccoFile("morocco.csv", ios::in);
    createVector(morocco, moroccoPlayers, moroccoFile);
    fstream franceFile("france.csv", ios::in);
    createVector(france, francePlayers, franceFile);
    fstream argentina2022File("argentina2022.csv", ios::in);
    createVector(argentina2022, argentinaMatches, argentina2022File);
    fstream croatia2022File("croatia2022.csv", ios::in);
    createVector(croatia2022, croatiaMatches, croatia2022File);
    fstream morocco2022File("morocco2022.csv", ios::in);
    createVector(morocco2022, moroccoMatches, morocco2022File);
    fstream france2022File("france2022.csv", ios::in);
    createVector(france2022, franceMatches, france2022File);
    }
    /* In this section, we take the 2D vector used for FIFA rankings and calculate
    a FIFA score for each team. This is done with different weights for each statistic.
    For example, the highest weight is the overall ranking, then the second tier would be
    passing, shooting, and defense, and so on.  f*/
    {
    double argentinaOverall = getScore(argentina, argentinaPlayers, 1);
    double argentinaPace = getScore(argentina, argentinaPlayers, 2);
    double argentinaShooting = getScore(argentina, argentinaPlayers, 3);
    double argentinaPassing = getScore(argentina, argentinaPlayers, 4);
    double argentinaDribbling = getScore(argentina, argentinaPlayers, 5);
    double argentinaDefense = getScore(argentina, argentinaPlayers, 6);
    double argentinaPhysical = getScore(argentina, argentinaPlayers, 7);

    double argentinaTotal = 0.33 * argentinaOverall + 0.08 * argentinaPace + 0.14  * argentinaShooting
     + 0.14 * argentinaPassing + 0.09 * argentinaDribbling + 0.14 * argentinaDefense + 0.08 * argentinaPhysical;

    cout << "Argentina: " << setprecision(5) << fixed << argentinaTotal << endl;

    double croatiaOverall = getScore(croatia, croatiaPlayers, 1);
    double croatiaPace = getScore(croatia, croatiaPlayers, 2);
    double croatiaShooting = getScore(croatia, croatiaPlayers, 3);
    double croatiaPassing = getScore(croatia, croatiaPlayers, 4);
    double croatiaDribbling = getScore(croatia, croatiaPlayers, 5);
    double croatiaDefense = getScore(croatia, croatiaPlayers, 6);
    double croatiaPhysical = getScore(croatia, croatiaPlayers, 7);

    double croatiaTotal = 0.33 * croatiaOverall + 0.09 * croatiaPace + 0.14  * croatiaShooting
     + 0.14 * croatiaPassing + 0.08 * croatiaDribbling + 0.14 * croatiaDefense + 0.08 * croatiaPhysical;

    cout << "croatia: " << croatiaTotal << endl;

    double moroccoOverall = getScore(morocco, moroccoPlayers, 1);
    double moroccoPace = getScore(morocco, moroccoPlayers, 2);
    double moroccoShooting = getScore(morocco, moroccoPlayers, 3);
    double moroccoPassing = getScore(morocco, moroccoPlayers, 4);
    double moroccoDribbling = getScore(morocco, moroccoPlayers, 5);
    double moroccoDefense = getScore(morocco, moroccoPlayers, 6);
    double moroccoPhysical = getScore(morocco, moroccoPlayers, 7);

    double moroccoTotal = 0.33 * moroccoOverall + 0.08 * moroccoPace + 0.14  * moroccoShooting
     + 0.14 * moroccoPassing + 0.09 * moroccoDribbling + 0.14 * moroccoDefense + 0.08 * moroccoPhysical;

    cout << "morocco: " << moroccoTotal << endl;

    double franceOverall = getScore(france, francePlayers, 1);
    double francePace = getScore(france, francePlayers, 2);
    double franceShooting = getScore(france, francePlayers, 3);
    double francePassing = getScore(france, francePlayers, 4);
    double franceDribbling = getScore(france, francePlayers, 5);
    double franceDefense = getScore(france, francePlayers, 6);
    double francePhysical = getScore(france, francePlayers, 7);

    double franceTotal = 0.33 * franceOverall + 0.08 * francePace + 0.14  * franceShooting
     + 0.14 * francePassing + 0.09 * franceDribbling + 0.14 * franceDefense + 0.08 * francePhysical;

    cout << "france: " << franceTotal << endl;
    }
    
    

    return 0;
}     

