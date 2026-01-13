from openai import OpenAI

client = OpenAI()

prompt = input("Prompt: ")

response = client.responses.create(
    model="gpt-5",
    input=prompt
)

print(response.output[0].content[0].text)
