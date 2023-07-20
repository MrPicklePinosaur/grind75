
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        T = [[] for i in range(numCourses)] # adjacency list

        # construct graph first
        for [course, preq] in prerequisites:
            if course == preq:
                return False

            T[course].append(preq)

        visited = [False for i in range(numCourses)]
        recStack = [False for i in range(numCourses)]

        def DFS(course):
            visited[course] = True
            recStack[course] = True

            for preq in T[course]:

                if recStack[preq] == True:
                    return False

                if visited[preq]== True:
                    continue

                if DFS(preq) == False:
                    return False

            recStack[course] = False

            return True


        for i in range(numCourses):
            if visited[i] == True:
                continue

            if DFS(i) == False:
                return False

        return True

        


