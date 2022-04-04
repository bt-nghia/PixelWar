def reversestring(s : str, index = 0) -> str:
    if index == len(s):
        return ""
    else:
        return s[len(s)-1-index] + reversestring(s, index+1)

if __name__=="__main__":
    strig = "nghiayeumaianh"
    print(reversestring(strig))