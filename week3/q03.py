
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points = sorted(points, key=lambda point: point[0]**2+point[1]**2)
        return points[:k]


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        H = []
        for point in points:
            dist = point[0]**2 + point[1]**2
            if len(H) < k:
                heappush(H, (-dist,  point))
            else:
                heappushpop(H, (-dist,  point))

        return [heappop(H)[1] for i in range(k)] 
                

