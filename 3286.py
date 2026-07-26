from collections import deque
from typing import List

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        rows = len(grid)
        cols = len(grid[0])

        INF = float("inf")
        dist = [[INF] * cols for _ in range(rows)]

        dq = deque()

        dist[0][0] = grid[0][0]
        dq.append((0, 0))

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while dq:
            x, y = dq.popleft()

            for dx, dy in directions:
                nx = x + dx
                ny = y + dy

                if 0 <= nx < rows and 0 <= ny < cols:

                    newDamage = dist[x][y] + grid[nx][ny]

                    if newDamage < dist[nx][ny]:
                        dist[nx][ny] = newDamage

                        if grid[nx][ny] == 0:
                            dq.appendleft((nx, ny))
                        else:
                            dq.append((nx, ny))

        return dist[rows - 1][cols - 1] < health