import sys
import ollama

def main():
    """
    Main function to process user query and return chatbot response.
    """
    if len(sys.argv) < 2:
        print("Error: Missing query argument.", file=sys.stderr)
        sys.exit(1)

    query = sys.argv[1]  # Read user input from command-line argument
    
    try:
        # Call the Ollama API with the user's query
        response = ollama.chat(
            model="deepseek-r1",
            messages=[{"role": "user", "content": query}]
        )

        # Print the chatbot's response (to be captured by the C++ program)
        print(response["message"]["content"])

    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
