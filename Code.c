# PPS_Project_VaishnaviShukla_88
Digital Voting and Result Processing System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Candidate
struct Candidate {
    int id;
    char name[50];
    int votes;
};

// Structure for Voter
struct Voter {
    int id;
    char name[50];
    int voted; // 0: not voted, 1: voted
};

// Node for dynamic linked list of Candidates
typedef struct CandNode {
    struct Candidate cand;
    struct CandNode* next;
} CandNode;

// Node for dynamic linked list of Voters
typedef struct VoterNode {
    struct Voter voter;
    struct VoterNode* next;
} VoterNode;

// Global pointers for dynamic lists
CandNode* candidates = NULL;
VoterNode* voters = NULL;

// Function to register a candidate (adds to dynamic list)
void registerCandidate() {
    CandNode* newNode = (CandNode*)malloc(sizeof(CandNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter Candidate ID: ");
    scanf("%d", &newNode->cand.id);
    printf("Enter Candidate Name: ");
    scanf("%s", newNode->cand.name);
    newNode->cand.votes = 0;
    newNode->next = NULL;
    
    // Check for unique ID
    CandNode* temp = candidates;
    while (temp != NULL) {
        if (temp->cand.id == newNode->cand.id) {
            printf("Candidate ID already exists!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    
    // Add to list
    if (candidates == NULL) {
        candidates = newNode;
    } else {
        temp = candidates;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Candidate registered successfully!\n");
}

// Function to register a voter (adds to dynamic list)
void registerVoter() {
    VoterNode* newNode = (VoterNode*)malloc(sizeof(VoterNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter Voter ID: ");
    scanf("%d", &newNode->voter.id);
    printf("Enter Voter Name: ");
    scanf("%s", newNode->voter.name);
    newNode->voter.voted = 0;
    newNode->next = NULL;
    
    // Check for unique ID
    VoterNode* temp = voters;
    while (temp != NULL) {
        if (temp->voter.id == newNode->voter.id) {
            printf("Voter ID already exists!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    
    // Add to list
    if (voters == NULL) {
        voters = newNode;
    } else {
        temp = voters;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Voter registered successfully!\n");
}
