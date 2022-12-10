# -*- coding: utf-8 -*-
"""
Created on Sat Dec 10 15:31:37 2022

@author: Grétar Már Kjartansson
"""

"""
A child is playing with a ball on the nth floor of a tall building. The 
height of this floor above ground level, h, is known.

He drops the ball out of the window. The ball bounces (for example), to 
two-thirds of its height (a bounce of 0.66).

His mother looks out of a window 1.5 meters from the ground.

How many times will the mother see the ball pass in front of her window 
(including when it's falling and bouncing?
 
Three conditions must be met for a valid experiment:

*Float parameter "h" in meters must be greater than 0
*Float parameter "bounce" must be greater than 0 and less than 1
*Float parameter "window" must be less than h.

If all three conditions above are fulfilled, return a positive integer, 
otherwise return -1.

Note:
The ball can only be seen if the height of the rebounding ball is strictly 
greater than the window parameter.

Examples:
- h = 3, bounce = 0.66, window = 1.5, result is 3

- h = 3, bounce = 1, window = 1.5, result is -1 

(Condition 2) not fulfilled).
"""

#1. nth floor height h from the ground
#2. Mom is placed 1.5m from the ground
#3. How many time will the mom see the ball pass the window? (up and down)
#4. Valid experimetns if: h>0, bounce>0 and bounce<1, window<h
    # if valid experiments fulfilled, return pos int, else -1.
#5. Ball seen only if h of bounching ball > window
#6. A ball bounce that is 2/3 of nth floor height is (0.66)
#7. h=3, bounce=0.66, window=1.5, result=3
    # h=3, bounce=1, window=1.5, result=-1  (Not fulfilled condition)


def bouncing_ball(h, bounce, window):
    count = 1
    
    if h>0 and bounce>0 and bounce<1 and window<h:
        h = h*bounce
        
        while(h>window):
            count += 2
            h = h*bounce
        
        return count
    else:
        return -1
    
def bouncingBall2(h, bounce, window):
    if not 0 < bounce < 1: return -1
    count = 0
    while h > window:
        count += 1
        h *= bounce
        if h > window: count += 1
    return count or -1

def bouncingBall3(h, bounce, window):
    seen = -1
    
    if 0 < bounce < 1:
        while h > window > 0:
            seen += 2
            h *= bounce
    
    return seen

import math

def bouncingBall4(h, bounce, window):
    # If parameters don't fulfil conditions, return -1
    if not (h > 0 and 0 < bounce < 1 and window < h):
        return -1
    # Solve equation for f(x) = window, using logarithms
    bounces = math.log(window / h, bounce)
    # Get actual number of bounces that still puts the ball above window height
    exactBounces = math.floor(bounces)
    # If last bounce is not strictly higher than window height, it can't be seen
    if bounces == exactBounces: 
        exactBounces -= 1
    # The ball will pass the window two times for each bounce, up and down, 
    # plus one for the initial drop past window, before first bounce
    passes = exactBounces * 2 + 1
    return passes

print(bouncing_ball(3, 0.66, 1.5))

















