#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
 * 
 */
// 超时，大量重复的机票
class Solution {
    vector<string> path;
    static bool cmp_to_key(vector<string> &ticket_a, vector<string> &ticket_b) {
        if (ticket_a[0] != ticket_b[0]) {
            return ticket_a[0] < ticket_b[0];
        }
        return ticket_a[1] < ticket_b[1];
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(), false);
        sort(tickets.begin(), tickets.end(), cmp_to_key);
        path.push_back("JFK");
        backtrace(tickets, used);
        return path;
    }

    bool backtrace(vector<vector<string>>& tickets, vector<bool> &used) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
        if (path.size() == tickets.size() + 1) {
            return true;
        }

        string startSite = path.back();
        for (int i = 0; i < tickets.size(); ++i) {
            auto &ticket = tickets[i];
            if (!used[i] && ticket[0] == startSite) {
                used[i] = true;
                path.push_back(ticket[1]);
                if (backtrace(tickets, used)) {
                    return true;
                }
                used[i] = false;
                path.pop_back();
            }
        }

        return false;
    }


};


class Solution1 {
    vector<string> path;
    map<string, map<string, int>> num_tickets;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &ticket : tickets) {
            ++num_tickets[ticket[0]][ticket[1]];
        }
        backtrace(tickets);
        return path;
    }

    bool backtrace(vector<vector<string>>& tickets) {
        if (path.size() == tickets.size() + 1) {
            return true;
        }

        string startSite = path.back();
        for (auto &nextSite : num_tickets[startSite]) {
            if (nextSite.second > 0) {
                --num_tickets[startSite][nextSite.first];
                path.push_back(nextSite.first);
                if (backtrace(tickets)) {
                    return true;
                }
                ++num_tickets[startSite][nextSite.first];
                path.pop_back();
            }
        }

        return false;
    }

    
};