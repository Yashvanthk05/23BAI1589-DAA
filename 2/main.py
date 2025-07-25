import random
import names
import csv

job_roles = [
    "HRM", "HRBP", "HRGA", "HRD",
    "CFO", "FP&A", "ACC", "AP/AR", "FA",
    "CMO", "PM", "SMM", "SEO", "PPC",
    "VP of Sales", "AE", "SDR", "BDM",
    "CIO", "Dev", "QA", "SysAdmin", "DBA", "ITSM", "DevOps", "CTO", "PMO", "Network Admin", "Security Analyst", "UX/UI", "Data Scientist", "Data Analyst", "Cloud Engineer",
    "GC", "AGC", "IP", "Corp Counsel",
    "COO", "Ops Manager", "Procurement Manager", "Supply Chain Analyst",
    "CSM", "CSR", "Support Engineer", "Help Desk",
    "CPO", "PM", "UX Designer", "Product Analyst"
]

DATASET_DIR="dataset"

def best_scenario(size):
    num=1
    with open(f"{DATASET_DIR}/ascending_employees_{size}.csv","w",newline='') as f:
        writer=csv.writer(f)
        writer.writerow(["EmployeeID","Name","Department","Salary"])
        while num<=5000:
            writer.writerow([num,names.get_full_name(),random.choice(job_roles),random.randrange(10000,150000)])
            num+=1
        
def worst_scenario(size):
    num=size
    with open(f"{DATASET_DIR}/descending_employees_{size}.csv","w",newline='') as f:
        writer=csv.writer(f)
        writer.writerow(["EmployeeID","Name","Department","Salary"])
        while num>0:
            writer.writerow([num,names.get_full_name(),random.choice(job_roles),random.randrange(10000,150000)])
            num-=1

def average_scenario(size):
    idx=[i for i in range(1,size+1)]
    random.shuffle(idx)
    with open(f"{DATASET_DIR}/random_employees_{size}.csv","w",newline="") as f:
        writer=csv.writer(f)
        writer.writerow(["EmployeeID","Name","Department","Salary"])
        for i in idx:
            writer.writerow([i,names.get_full_name(),random.choice(job_roles),random.randrange(10000,150000)])

def main():
    best_scenario(5000)
    best_scenario(10000)
    best_scenario(20000)
    worst_scenario(5000)
    worst_scenario(10000)
    worst_scenario(20000)
    average_scenario(5000)
    average_scenario(10000)
    average_scenario(20000)

if __name__ == "__main__":
    main()