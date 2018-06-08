M = []
Schedule = []
def maximum(a,b):
    if a > b :
        return a
    else:
        return b
def calculate_predecessor(jobs,n):
    p = [0 for i in range(n+1)]
    cur_job = n
    chosen_job = cur_job - 1
    while cur_job > 1 :
        if chosen_job <= 0 :
            p[cur_job] = 0
            cur_job=cur_job-1
            chosen_job=cur_job-1

        else:
            if jobs[cur_job][0] < jobs[chosen_job][1]:
                chosen_job = chosen_job - 1
            else:
                p[cur_job] = chosen_job
                cur_job = cur_job-1
                chosen_job = cur_job -1
    return p
def opt(j,jobs,p):
    global M
    if j == 0:
        return M[j]
    elif j ==1:
        M[j] = maximum(jobs[j][2],0)
        return M[j]
    else:
        if M[j] == -1:
            M[j] = maximum(opt(j-1,jobs,p),jobs[j][2]+opt(p[j],jobs,p))
        return M[j]
def wis(jobs,n):
    p =  calculate_predecessor(jobs,n)
    value = opt(n,jobs,p)
    return value,p
def find_solution(j,jobs,p):
    global M
    global Schedule
    if j > 0 :
        if jobs[j][2] + M[p[j]] >= M[j-1]:
            Schedule.append(j)
            find_solution(p[j],jobs,p)
        else:
            find_solution(j-1,jobs,p)
    return
def main():
    n = int(input("Enter the number of jobs: "))
    global M
    M = [-1 for i in range(n+1)]
    M[0] = 0
    jobs = [0]
    for i in range(n):
        s = int(input("Start time: "))
        f = int(input("Finish time: "))
        v = int(input("Value: "))
        jobs.append((s,f,v))
    max_value,p = wis(jobs,n)
    print(M)
    print(max_value)
    global Schedule
    find_solution(n,jobs,p)
    print(Schedule)
    return
main()
