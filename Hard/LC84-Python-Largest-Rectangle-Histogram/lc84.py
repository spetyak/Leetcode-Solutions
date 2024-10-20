
"""
Author: spetyak

Runtime: Beats 99.80% of Python submissions
Memory: Beats 12.40% of Python submissions

"""

class Solution(object):

    def largestRectangleArea(self, heights):
        """
        Given an array of integers heights representing the histogram's bar height
        where the width of each bar is 1, returns the area of the largest rectangle in the histogram.

        Args:
            heights (List[int]): the array of integers representing the bars of a histogram

        Returns:
            int: the area of the largest rectangle in the histogram
        """
        
        stack = []  # a increasing monotonic stack of the heights of the histogram 
        maxArea = 0 # the maximum rectangle area found so far
        
        for i in range(len(heights)):
            
            # if the stack is not empty and the current height is less than the top of the stack
            if len(stack) > 0 and heights[i] < stack[-1][1]:
            
                # remove elements larger than the current height and check their areas as they are popped
                while (len(stack) > 0 and heights[i] < stack[-1][1]):
                    
                    poppedHeight = stack.pop()
                    width = i - poppedHeight[0]
                    height = poppedHeight[1]
                    
                    currentArea = width * height # determine the area of the popped rectangle
                    
                    # update max area
                    if currentArea > maxArea:
                        
                        maxArea = currentArea
                        
                stack.append((poppedHeight[0], heights[i])) # add new height to stack, able to form rectangle with last popped element
                
            else:
            
                stack.append((i, heights[i])) 
                

        
        # pop remaining elements from stack checking the are of the rectangles than can form
        end = len(heights)
        while len(stack) > 0:
            
            poppedHeight = stack.pop()
            width = end - poppedHeight[0]
            height = poppedHeight[1]
            
            currentArea = width * height # determine the area of the popped rectangle
            
            # update max area
            if (currentArea > maxArea):
                
                maxArea = currentArea
        
        return maxArea
    
def main():

    sol = Solution()
    
    heights = [2,1,2] 
    
    print(f"Output: {sol.largestRectangleArea(heights)}")

    return

if __name__ == "__main__":
    main()
    