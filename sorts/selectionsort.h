template <class T>
void selection_sort(std::vector <T> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int min = i;
        for(int j = i+1; j < nums.size(); j++)
        {
            if(nums[min] > nums[j])
                min = j;
        }
        std::swap(nums[i],nums[min]);
    }
}