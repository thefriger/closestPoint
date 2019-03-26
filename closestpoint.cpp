#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>


int main () {
    int refX, refY, distanceX, distanceY, distanceHyp;
    refX = refY= 0;
    std::vector<std::vector<int> > points = {{-2, 4},{0, -2}, {-1, 0}, {3, 5}, {-2, 3}, {3, 2}};
    std::vector<int> distancesHyp;

    for(size_t i=0; i<points.size(); i++){
        distanceX = abs(points[i][0] - refX);
        for(size_t j=0; j<points[i].size()-1; j++){
            distanceY = abs(points[i][1] - refY);
            distanceHyp = floor(sqrt(distanceX*distanceX + distanceY*distanceY));
            distancesHyp.push_back(distanceHyp);
        }
    }

// For finding the maximum distance in the vector
//    int maxElementIndex = std::max_element(distancesHyp.begin(),distancesHyp.end()) - distancesHyp.begin();
//    int maxElement = *std::max_element(distancesHyp.begin(), distancesHyp.end());

    int minElementIndex = std::min_element(distancesHyp.begin(),distancesHyp.end()) - distancesHyp.begin();
    int minElement = *std::min_element(distancesHyp.begin(), distancesHyp.end());

    printf( "The closest point is:\n\tx: %i,\ty: %i\t distance to the ref. point is: %i\n", points[minElementIndex][0], points[minElementIndex][1], minElement);

    return 0;
}
