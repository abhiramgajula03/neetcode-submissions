class Solution { 
public: 
    int maxArea(vector<int>& heights) { 
        int n=heights.size(); 
        int i=0,j=n-1; 
        int diff=0,minimum=0; 
        int mini=INT_MAX; 
        
        while(i<j){ 
            
            diff=min(heights[i],heights[j])*(j-i);
            
            if(diff>minimum){ 
                minimum=diff; 
            }
            
            if(heights[i]<heights[j]){ 
                i++; 
            } 
            else{ 
                j--; 
            } 
        } 
        
        return minimum; 
    } 
};