# Astrobot

A simple modular general purpose bot for personal server

## Installation

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Create and activate a virtual environment.
4. Install the required packages by running `pip install -r requirements.txt`.

## Usage



## Examples



## License




## Module 1: Cricket Score Serant [Work in progress]
This module is intended to display a live cricket score card in any text channel of the discord server when requested. Currently the api is liminted to free access of 100 hits per day, so score updates can only be done for one game per day with a refresh rate of 1 update per over. 

### Submodule 1: Hit Limiter
To ensure that api does not exceed number of hits per day a token bucket system needs to be implemented with a token refil rate of 100 tokens per day. The API requests need to be coupled with a token_usage() function. Further more the run time token and capacity count need to be stored in a file that can be reffered to in case of app restarts. 

### Submodule 2: Scorrer 
1. Request score updates at exactly or approxiamately 1 update per over.
        *TODO: Researh similar open source api's and their techniques. Think of the most optimized algorithm that ensures curcial and timely information delivery ith limited resources. (ML ?)

2. Post a message on the channel consisting of a summary of the current score and edit it wwith eah API hit. 
        *TODO: Read eddit message documentation of the discord bot and implement it.


## About
The bot is deployed in development modes and if Master Charania is busy **not** doing batman stuff in areas without internet access Astrobot might be down. Sorry what? Is Master Charania batman? NO! Why'd you ask? This is a readme file not a press conference

### Auther: Sarim Charania
