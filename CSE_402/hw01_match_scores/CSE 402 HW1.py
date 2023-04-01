#!/usr/bin/env python
# coding: utf-8

# In[7]:


finger_genuine_file = open("finger_genuine.score")
finger_impostor_file = open("finger_impostor.score")
hand_genuine_file = open("hand_genuine.score")
hand_impostor_file = open("hand_impostor.score")

finger_genuine_file_list = finger_genuine_file.readlines()
finger_impostor_file_list = finger_impostor_file.readlines()
hand_genuine_file_list = hand_genuine_file.readlines()
hand_impostor_file_list = hand_impostor_file.readlines()

for values in range(len(finger_genuine_file_list)):
    finger_genuine_file_list[values] = (float(finger_genuine_file_list[values]))
    
for values in range(len(finger_impostor_file_list)):
    finger_impostor_file_list[values] = (float(finger_impostor_file_list[values]))
    
for values in range(len(hand_genuine_file_list)):
    hand_genuine_file_list[values] = (float(hand_genuine_file_list[values]))
    

for values in range(len(hand_impostor_file_list)):
    hand_impostor_file_list[values] = (float(hand_impostor_file_list[values]))

print(len(finger_genuine_file_list))
print(len(finger_impostor_file_list))
print(len(hand_genuine_file_list))
print(len(hand_impostor_file_list))


# In[8]:


finger_maximum_value = max(finger_genuine_file_list),max(finger_impostor_file_list)
finger_minimum_value = min(finger_genuine_file_list),min(finger_impostor_file_list)

hand_maximum_value = max(hand_genuine_file_list),max(hand_impostor_file_list)
hand_minimum_value = min(hand_genuine_file_list),min(hand_impostor_file_list)

print(finger_maximum_value)
print(finger_minimum_value)

print(hand_maximum_value)
print(hand_minimum_value)


# In[9]:


threshold = 45
false_match_rate_finger = 0

for count in range(len(finger_impostor_file_list)): 
    if finger_impostor_file_list[count] >= threshold:
        false_match_rate_finger+=1

false_match_rate_hand = 0
for count in range (len(hand_impostor_file_list)):
    if hand_impostor_file_list[count] <= threshold:
        false_match_rate_hand+=1
        
fmr_similarity=false_match_rate_finger/len(finger_impostor_file_list)
fmr_disimilarity=false_match_rate_hand/len(hand_impostor_file_list)

print("False Match Rate Similarity = ",round(fmr_similarity*100,2),"%")
print("False Match Rate Dissimilarity = ",round(fmr_disimilarity*100,2),"%")


# In[10]:


threshold = 45
false_non_match_rate_finger = 0
false_non_match_rate_hand = 0

for i in range(len(finger_genuine_file_list)): 
    if finger_genuine_file_list[i] < threshold:
        false_non_match_rate_finger+=1


for j in range (len(hand_genuine_file_list)):
    if hand_genuine_file_list[j] > threshold:
        false_non_match_rate_hand+=1
             
fnmr_similarity=false_non_match_rate_finger/len(finger_genuine_file_list)
fnmr_disimilarity=false_non_match_rate_hand/len(hand_genuine_file_list)

print("False Non-Match Rate Similarity = ",round(fnmr_similarity*100,2),"%")
print("False Non-Match Rate Dissimilarity = ",round(fnmr_disimilarity*100,2),"%")

