def job_sequencing(jobs):
    
    jobs.sort(key=lambda x: x[2], reverse=True)
    
    max_deadline = max(job[1] for job in jobs)
    
    result = [-1] * max_deadline
    slot = [False] * max_deadline
    
    # Fill the result array
    for i in range(len(jobs)):
        # Find a free slot from the last possible position
        for j in range(min(max_deadline-1, jobs[i][1]-1), -1, -1):
            if not slot[j]:
                result[j] = jobs[i][0]
                slot[j] = True
                break
    
    return [x for x in result if x != -1]



jobs = [(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)]  # (job_id, deadline, profit)
print("Job sequence:" , job_sequencing(jobs))