import requests


class CricketScoreChecker:
    def __init__(self):
        # Replace YOUR_API_KEY with your actual API key
        self.api_key = "YOUR_API_KEY"
        # Define the API endpoint URL
        self.url = "https://api.example.com/endpoint"
        # Add the API key to the request headers
        self.headers = {"apikey": self.api_key}

    def check_score(self, match_id):
        """
        This method can be used to check the score of a cricket match by its match_id
        """
        pass
    def check_live_matches(self):
        # Send a GET request to the API endpoint
        response = requests.get(self.url, headers=self.headers)
        data = response.json()
        print(summary(data))

    '''TODO: Define a hit counter and perform unit testing, ensure that the counter doesnt reset by program reset using a alue storedd in a file.'''











# Print the response from the API
#print(response.json())


    def summary(self,data):
        match_data = data["data"][0]
        match_name = match_data["name"]
        match_status = match_data["status"]
        match_venue = match_data["venue"]
        match_date = match_data["date"]
        match_teams = match_data["teams"]
        score = match_data["score"]
        team1_score = score[0]["r"]
        team2_score = score[1]["r"]
        summary = f"{match_name} - {match_status}\nVenue: {match_venue}\nDate: {match_date}\nTeams: {match_teams[0]} vs {match_teams[1]}\nScore: {match_teams[0]}: {team1_score} - {match_teams[1]}: {team2_score}\n"
        return summary

#print(summary(data))
