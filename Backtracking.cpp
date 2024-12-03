#include <iostream>
#include<vector>

//Warnsdorff's algorithm for knights's tour problem
bool isPossible(std::vector<std::vector<int>> dots, std::vector<int> rStep, std::vector<int> cStep,int& n,int size,int row,int col,std::vector<std::vector<bool>> visited)
{

    if (n == (size * size))
    {
        return true;
    }
    if (row < 0 || row >= size || col < 0 || col >= size)
    {
        return false;
    }
    visited[row][col] = true;
    for (int i = 0; i < 8; i++)
    {
        int nRow = row + rStep[i];
        int nCol = col + cStep[i];
        if (nRow<size&&nRow>=0&&nCol>=0&&nCol<size&&!visited [nRow][nCol])
        {
            n++;
            if (isPossible(dots, rStep, cStep, n, size, row, col , visited))
            {
                return true;
            }
            visited[row][col] = false;
            n--;
        }
        row -= rStep[i];
        col -= cStep[i];
    }
    visited[row][col] = false;
    return false;
}

//dfs to find hamiltonian cycle
bool FindHamilCycle(std::vector<std::vector<int>> nums, int size, std::vector<bool> visited,int count,int current,int startNode)
{
    if (count == size )
    {
        return current==startNode;
    }
    visited[current] = true;
    for (int i : nums[current])
    {
        if (!visited[i]||(i==startNode&&count==size-1))
        {
            if (FindHamilCycle(nums, size, visited, count + 1, i, startNode))
            {
                return true;
            }
        }
    }
    visited[current] = false;
    return false;
}
bool FindHCycle(std::vector<std::vector<int>> nums, int size)
{
    std::vector<bool> visited(size, false);
    for (int i = 0; i < size; i++)
    {
        if (FindHamilCycle(nums, size, visited, 0, i, i))
        {
            std::cout << "Starting node is: " << i << std::endl;
            //std::cout << "hlfsdf";
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<int> rStep = { 2,1,-1,-2,-2,-1,1,2 };
    std::vector<int> cStep = { 1,2,2,1,-1,-2,-2,-1 };
    //int size;
    //std::cin >> size;
    //std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
    //std::vector<std::vector<int>> dots(size, std::vector<int>(size, 1));
    //int n = 1;
    //std::cout << isPossible(dots, rStep, cStep, n, size, 0, 0, visited);
    std::vector <std::vector<int>> nums = { {1,3},{0,2,3,4},{1,4},{0,1,4},{3,1,2} };
    std::cout << FindHCycle(nums, 5);
}


