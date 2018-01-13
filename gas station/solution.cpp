/**
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
**/

/**
My O(n) solution using two passes:
a forward one to see the lowest the tank will get 
to reach each station from the end, 
and reverse one to see how much gas is left at then end 
starting from each station
**/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> gasToReachFromEnd = vector<int>(gas.size());
        vector<int> netGasLostFromEnd = vector<int>(gas.size());
        int numStations = gas.size();
        int gasAtEnd;
        
        netGasLostFromEnd[0] = cost.back() - gas.back();
        int maxGasLost = netGasLostFromEnd[0];
        gasToReachFromEnd[0] = maxGasLost;
        for(int i = 1; i < numStations; ++i){
            netGasLostFromEnd[i] = netGasLostFromEnd[i - 1]  + cost[i - 1] - gas[ i - 1];
            maxGasLost = std::max(netGasLostFromEnd[i], maxGasLost);
            gasToReachFromEnd[i] = maxGasLost;
        }
        
        gasAtEnd = 0;
        if(gasAtEnd >= gasToReachFromEnd[numStations - 1]) return numStations - 1;
        for(int i = gas.size() - 2 ; i >= 0; --i){
            gasAtEnd += gas[i] - cost[i];
            if(gasAtEnd >= gasToReachFromEnd[i]) return i;
        }        
        return - 1;
    }
};
            
