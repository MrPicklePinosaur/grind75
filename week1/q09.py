# Flood Fill

DIRS =  [(+1, 0), (0, -1), (-1, 0), (0, +1)]

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        replace_color = image[sr][sc]
        h = len(image)
        w = len(image[0])

        visited = set([])
        q = [(sc, sr)]

        while len(q) != 0:
            (nx, ny) = q.pop(0)
            image[ny][nx] = color

            # find neighbours
            neighbours = [(dx+nx, dy+ny) for (dx, dy) in DIRS]
            neighbours = [(x, y) for (x, y) in neighbours if ( (0 <= x and x < w and 0 <= y and y < h) and image[y][x] == replace_color and ((x, y) not in visited))]

            q.extend(neighbours)

            visited.add((nx, ny))

        return image


