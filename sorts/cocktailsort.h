template <class T>
void cocktail_sort(std::vector <T> &nums)
{
    int bot = 0;
    int top = nums.size()-1;
    while(bot<top)
    {
        for(int i = bot; i < top ; i++)
        {
            if(nums[i] > nums[i+1])
            {
                std::swap(nums[i],nums[i+1]);
            }
        }
        top--;
        for(int i = top; i > bot ; i--)
        {
            if(nums[i] < nums[i-1])
            {
                std::swap(nums[i],nums[i-1]);
            }
        }
        bot++;
    }
}