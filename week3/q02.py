class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        H, W = len(mat), len(mat[0])

        Q = deque()
        visited = set()

        ret = [[0 for _ in range(W)] for _ in range(H)]
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        # insert all 0's into queue
        for j in range(H):
            for i in range(W):
                if mat[j][i] == 0:
                    Q.append((i, j))
                    visited.add((i, j))

        # print(Q)
        dis = 0 
        while len(Q) > 0:
            L = len(Q) 
            for _ in range(L):
                (x, y) = Q.popleft()
                # print((x, y))

                if mat[y][x] == 1:
                    ret[y][x] = dis

                for (dx, dy) in dirs:
                    nx, ny = x+dx, y+dy
                    if ((nx, ny) not in visited) and 0 <= nx and nx < W and 0 <= ny and ny < H:
                        Q.append((nx, ny))
                        visited.add((nx,ny))

            dis += 1

        return ret


# DP solution
        
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        H, W = len(mat), len(mat[0])

        ret = [[0 for _ in range(W)] for _ in range(H)]

        # traverse top down
        for j in range(H):
            for i in range(W):
                if mat[j][i] == 1:
                    check = [100000000]
                    if 0 <= i-1:
                        check.append(ret[j][i-1]+1)
                    if 0 <= j-1:
                        check.append(ret[j-1][i]+1)
                    
                    ret[j][i] = min(check)

        # print(ret)
        # traverse bottum up
        for j in reversed(range(H)):
            for i in reversed(range(W)):
                if mat[j][i] == 1:
                    check = [ret[j][i]]
                    if i+1 < W:
                        check.append(ret[j][i+1]+1)
                    if j+1 < H:
                        check.append(ret[j+1][i]+1)
                    
                    ret[j][i] = min(check)


        return ret



        
