#!/usr/bin/python3.5
# -*- UTF-8 -*-
import re
from bs4 import BeautifulSoup
import requests
import os
import sys
'''
problem_order=a1020
'''
compile_sh_seg='''
edit_order=0
input_order=0
output_name=helloworld.exe

workdir=~/workspace/algorithm_log
problemdir=$workdir/pat_$problem_order
g++ -w -std=c++11 $problemdir/pat_${problem_order}_${edit_order}.cpp -o $problemdir/$output_name

$problemdir/$output_name <${problemdir}/pat_${problem_order}_input_${input_order}.txt
rm $problemdir/$output_name


'''


def get_html(url):
    try:
        r=requests.get(url,timeout=30)
        r.raise_for_status()
        r.encoding=r.apparent_encoding
        return r.text
    except:
        raise Exception("Exceptiong:internet error.Canot make files.")

def get_content(soup_segment):
    stack=[]
    result=""
    stack.append(soup_segment)
    while len(stack)>0:
        item=stack.pop()
        if item.string is None:
            subitem_lst=item.contents
            for i in range(len(subitem_lst)-1,-1,-1):
                stack.append(subitem_lst[i])
        else:
            #because python automate memory
            #that segment might be very slow when deal with large file
            ##########################################################
            if item.name=='p':
                result=result+"\n"
            result=result+item.string
            ##########################################################
    return result
if len(sys.argv)==1:
    problem_order=input("please input problem order:")
else:
    problem_order=sys.argv[1]
compile_sh="problem_order="+problem_order+"\n"+compile_sh_seg
compile_sh_path="/home/ruici/workspace/c_c++/scripts/algorithm_log.sh"
if problem_order[0]=='b':
    url_root='https://www.patest.cn/contests/pat-b-practise/'
elif problem_order[0]=='a':
    url_root='https://www.patest.cn/contests/pat-a-practise/'
else:
    print("wrong")
    exit(1)
path_root="/home/ruici/workspace/algorithm_log/pat_"
path=path_root+problem_order
url=url_root+problem_order[1:]
input_path=path+"/"+"pat"+"_"+problem_order+"_input_"
output_path=path+"/"+"pat"+"_"+problem_order+"_output_"
question_path=path+"/"+"pat"+"_"+problem_order+"_question"+".txt"

if os.path.exists(path):
    print("You have made that files,and not need make again.")
    exit()
try:
    page_text=get_html(url)
except Exception as e:
    print(e)
    exit(1)

if len(page_text)<=0:
    print("Error:Get Wrong text.")
    exit(1)
os.mkdir(path)
with open(compile_sh_path,"w") as f:
    f.write(compile_sh)
with open(path+"/page_text.html","w") as f:
    f.write(page_text)
with open(path+"/page_text.html","r") as f:
    page_text=f.read()
soup=BeautifulSoup(page_text,"html.parser")

problem_content=soup.find_all(id="problemContent")[0]

result=get_content(problem_content)

title=soup.find_all("title")[0].string+"\n"
with open(question_path,"w") as f:
    f.write(title)
    f.write(result)

s=problem_content.find_all('pre')
count=int(len(s)/2)
for i in range(0,count):
    m=open(input_path+str(i)+".txt",'w')
    m.write(s[i*2].string.strip("\n"))
    m.close()
    u=open(output_path+str(i)+".txt",'w')
    u.write(s[i*2+1].string.strip("\n"))
    u.close()

with open(path+"/"+"pat"+"_"+problem_order+"_0"+".cpp","w") as f:
    pass

