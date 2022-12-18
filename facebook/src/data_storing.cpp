/* *****************************************************************************
##
# @file        data_storing.cpp
# @brief       class implementation for permanent storing
# @copyright   MIT license
# ****************************************************************************/

#include <algorithm>
#include <map>
#include <sstream>
#include <vector>
#include "../include/data_storing.hpp"

string OUTPUT_PATH_GOT_1 = "C:\\Users\\lsm1so\\Documents\\workspace\\windows_tests\\facebook\\database\\got_1_result.csv";
string OUTPUT_PATH_NARUTO_1 = "C:\\Users\\lsm1so\\Documents\\workspace\\windows_tests\\facebook\\database\\naruto_1_result.csv";

map<themes,string> data_out_selection{
    {themes::GoT,OUTPUT_PATH_GOT_1},
    {themes::Naruto,OUTPUT_PATH_NARUTO_1},
};

CCurrentSession::CCurrentSession(themes f_theme) : m_theme{f_theme}
{
    while(m_record.name.length() == 0)
    {
        cout << "Please provide your name" << endl;
        cin >> m_record.name;
    }
    m_record.result = 0;
    m_record.attempts = 0;
    getHistory();
};

void CCurrentSession::set_duration(int f_duration)
{
    m_record.time = f_duration;
};

int CCurrentSession::get_score()
{
    return m_record.result;
};

void CCurrentSession::incr_score()
{
    m_record.result += 1;
};

void CCurrentSession::getHistory()
{
    ifstream fin(data_out_selection[m_theme].c_str());

    if(!fin.good())
    {
        cout << "No result yet" << endl;
    }
    else
    {
        // Read file
        string line;
        while(getline(fin,line))
        {
            record rec;
            stringstream ss(line);
            int iter{0};
            string word;

            while(getline(ss,word,','))
            {
                if(iter == 0) rec.result = stoi(word);
                else if (iter == 1) rec.time = stoi(word);
                else if (iter == 2) rec.name = word;
                else if (iter == 3) rec.attempts = stoi(word);
                else cout << "Error during reading records" << endl;
                iter++;
            }
            m_records.push_back(rec);
        }
    }
};

themes CCurrentSession::getTheme()
{
    return m_theme;
}

void CCurrentSession::updateRecords()
{
    m_records.push_back(m_record);
    sort(m_records.begin(),m_records.end(), [](const record & a, const record & b) -> bool{return a.result > b.result;});
};

void CCurrentSession::store()
{
    ofstream fout;
    fout.open((data_out_selection[m_theme].c_str()));
    for(auto& rec : m_records)
    {
        fout << to_string(rec.result) << "," << to_string(rec.time) << "," << rec.name << "," << rec.attempts << endl;
    }
    fout.close();
};

void CCurrentSession::displayScores()
{
    int index{1};
    for(const auto& rec : m_records)
    {
        cout << to_string(index) << " " << rec.name << " " << rec.result << "pts" << endl;
        if(index++ > 10) break;
    }
}

