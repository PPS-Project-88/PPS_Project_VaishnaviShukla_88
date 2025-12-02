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
// Priyanshu kumar
void castVote() {
    int voterId, candId;
    printf("Enter Voter ID: ");
    scanf("%d", &voterId);
    
    // Find voter
    VoterNode* voterTemp = voters;
    while (voterTemp != NULL) {
        if (voterTemp->voter.id == voterId) {
            if (voterTemp->voter.voted == 1) {
                printf("You have already voted!\n");
                return;
            }
            break;
        }
        voterTemp = voterTemp->next;
    }
    if (voterTemp == NULL) {
        printf("Voter not found!\n");
        return;
    }
    
    printf("Enter Candidate ID to vote for: ");
    scanf("%d", &candId);                                                                   // Find candidate and increment vote
    CandNode* candTemp = candidates;
    while (candTemp != NULL) {
        if (candTemp->cand.id == candId) {
            candTemp->cand.votes++;
            voterTemp->voter.voted = 1;
            printf("Vote cast successfully!\n");
            return;
        }
        candTemp = candTemp->next;
    }
    printf("Candidate not found!\n");
}
// Functions to count votes and declare results(uses array for temporary vote counts if needed,but here directly from structures)
void countVotes() {
    if (candidates == NULL) {
        printf("No candidates registered!\n");
        return;
    }
    
    printf("\nElection Results:\n");
    CandNode* temp = candidates;
    int maxVotes = -1;
    char winner[50] = "";
    
    while (temp != NULL) {
        printf("Candidate ID: %d, Name: %s, Votes: %d\n", temp->cand.id, temp->cand.name, temp->cand.votes);
        if (temp->cand.votes > maxVotes) {
            maxVotes = temp->cand.votes;
            strcpy(winner, temp->cand.name);
        }
        temp = temp->next;
    }
    
    if (maxVotes > 0) {
        printf("Winner: %s with %d votes\n", winner, maxVotes);
    } else {
        printf("No votes cast yet.\n");
    }
}

// Function to save results to file
void saveResults() {
    FILE* file = fopen("election_results.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fprintf(file, "Election Results:\n");
    CandNode* temp = candidates;
    while (temp != NULL) {
        fprintf(file, "Candidate ID: %d, Name: %s, Votes: %d\n", temp->cand.id, temp->cand.name, temp->cand.votes);
        temp = temp->next;
    }
    fclose(file);
    printf("Results saved to file!\n");
}
\\  siddhant singh
