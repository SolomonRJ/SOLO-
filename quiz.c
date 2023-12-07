#include <microhttpd.h>
#include <stdio.h>
#include <string.h>

struct Question {
    char question[256];
    char answers[4][64];
    int correctAnswerIndex;
};

struct Question questions[] = {
    {"What is the capital of France?", {"Paris", "Berlin", "London", "Madrid"}, 0},
    {"Who is the Prime Minister of India?", {"Rahul Gandhi", "Narendra Modi", "Cristiano Ronaldo", "Solomon"}, 1},
    // Add more questions as needed
};

int scores[10]; // Assuming a maximum of 10 players; you may adjust this based on your needs
int currentQuestionIndex = 0;

static int answer_handler(void *cls, struct MHD_Connection *connection,
                           const char *url, const char *method,
                           const char *version, const char *upload_data,
                           size_t *upload_data_size, void **con_cls)
{
    const char *answer = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "answer");

    struct MHD_Response *response;
    char *resp_str;

    if (answer != NULL) {
        int selectedAnswerIndex = atoi(answer);
        int isCorrect = (selectedAnswerIndex == questions[currentQuestionIndex].correctAnswerIndex);

        scores[*con_cls] += isCorrect ? 1 : 0;

        resp_str = isCorrect ? "Correct!" : "Incorrect!";
        currentQuestionIndex++;
    } else {
        resp_str = "Invalid answer.";
    }

    response = MHD_create_response_from_buffer(strlen(resp_str), (void *)resp_str, MHD_RESPMEM_PERSISTENT);
    MHD_add_response_header(response, "Content-Type", "text/plain");
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);

    return ret;
}

int main()
{
    struct MHD_Daemon *daemon;

    // Initialize scores
    memset(scores, 0, sizeof(scores));

    // Start the HTTP server
    daemon = MHD_start_daemon(MHD_USE_AUTO | MHD_USE_INTERNAL_POLLING_THREAD,
                              8080, NULL, NULL, &answer_handler, NULL, MHD_OPTION_END);

    if (NULL == daemon)
        return 1;

    printf("Server started. Press enter to stop.\n");
    getchar();

    MHD_stop_daemon(daemon);

    return 0;
}
