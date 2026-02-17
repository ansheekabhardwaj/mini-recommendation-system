# mini recommendation system
A mini Movie Recommendation system coded using cosine similarity formula

## Project Overview

This is a simple collaborative filtering based Movie Recommendation System built in C++.

The system:
- Takes movie ratings from a user
- Compares them with other users
- Uses Cosine Similarity to find the most similar user
- Recommends the highest-rated unseen movie

This project demonstrates core concepts of recommendation systems and vector similarity.


## Concepts Used

- Cosine Similarity
- Collaborative Filtering
- Vectors and Dynamic Arrays
- Hash Maps (unordered_map)
- STL Algorithms
- Mathematical Vector Operations


## How It Works

### 1️⃣ Cosine Similarity

The similarity between two users is calculated using:

Similarity = (A · B) / (||A|| × ||B||)


Where:
- A · B = Dot product of rating vectors
- ||A|| = Magnitude of vector A
- ||B|| = Magnitude of vector B

The higher the value (closer to 1), the more similar the users.


### 2️⃣ Finding Most Similar User

The program:
- Compares the current user's ratings with all other users
- Selects the user with highest similarity score


### 3️⃣ Generating Recommendation

From the most similar user:
- Find movies the current user has not watched (rating = 0)
- Recommend the highest-rated unseen movie


## Project Structure

mini-recommendation-system/
│
├── maincode.cpp          # Core implementation
└── README.md         # Project documentation


## Author

Ansheeka Bhardwaj
Second year CSE undergrad