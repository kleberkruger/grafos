/*
 * MIT License
 *
 * Copyright (c) 2019 Kleber Kruger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef GRAPH_APPS_APPLICATION_H
#define GRAPH_APPS_APPLICATION_H


#include <chrono>
#include <string>
#include <vector>
#include <sys/fcntl.h>
#include <sys/filio.h>
#include <sys/ioctl.h>
#include <unistd.h>

/**
 * Representa uma tarefa da aplicação.
 */
struct Task {

    explicit Task(std::string description) : description(std::move(description)),
                                             start(std::chrono::high_resolution_clock::now()) {}

    std::string description;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point finish;
};

/**
 * Application é uma classe base com métodos para o gerenciamento de tarefas de uma aplicação.
 */
class Application {
protected:

    template<typename F, typename... Args>
    using ReturnType = typename std::result_of<F(Args...)>::type;

    /**
     * Executa uma tarefa.
     *
     * @tparam F
     * @tparam Args
     * @param description
     * @param func
     * @param args
     * @return
     */
    template<typename F, typename... Args>
    typename std::enable_if_t<std::is_same_v<ReturnType<F, Args...>, void>>
    runTask(const std::string &description, F &&func, Args &&... args) {
        Task task = initializeTask(description);
        std::forward<decltype(func)>(func)(std::forward<decltype(args)>(args)...);
        finalizeTask(task);
    }

    /**
     * Executa uma tarefa.
     *
     * @tparam F
     * @tparam Args
     * @param description
     * @param func
     * @param args
     * @return
     */
    template<typename F, typename... Args>
    typename std::enable_if_t<!std::is_same_v<ReturnType<F, Args...>, void>, ReturnType<F, Args...>>
    runTask(const std::string &description, F &&func, Args &&... args) {
        Task task = initializeTask(description);
        auto ret = std::forward<decltype(func)>(func)(std::forward<decltype(args)>(args)...);
        finalizeTask(task);
        return ret;
    }

//    template<typename F, typename... Args>
//    void runTask(std::true_type, const std::string &name, F &&func, Args &&... args) { /* void */ }
//
//    template<typename F, typename... Args>
//    ReturnType<F, Args...>
//    runTask(std::false_type, const std::string &name, F &&func, Args &&... args) { /* non-void */ }
//
//    template<typename F, typename... Args>
//    ReturnType<F, Args...> runTask(const std::string &name, F &&func, Args &&... args) {
//        return runTask(std::is_void<ReturnType<F, Args...>>{}, name, func, args...);
//    }

    /**
     * Lê um arquivo de entrada.
     *
     * @param filePath
     * @return
     */
    static std::string readInputFile(const std::string &filePath) {
        char buffer[BUFFER_SIZE];
        int fd, ret;

        if ((fd = open(filePath.data(), O_RDONLY)) == -1) {
            throw std::invalid_argument("Incorrect input file path: \"" + filePath + "\"");
        }

        std::size_t size;
        ioctl(fd, FIONREAD, &size);
        std::string text;
        text.reserve(size);

        while ((ret = read(fd, buffer, sizeof(buffer))) > 0) {
            buffer[ret] = '\0';
            text.append(buffer);
        }

        return text;
    }

    /**
     * Escreve em um arquivo de saída.
     *
     * @param filePath
     * @param text
     */
    static void printOutputFile(const std::string &filePath, const std::string &text) {
        int fd;

        if ((fd = open(filePath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH)) == -1) {
            throw std::invalid_argument("Incorrect output file path: \"" + filePath + "\"");
        }

        write(fd, text.c_str(), text.size());
    }

private:

    static constexpr int BUFFER_SIZE = 65536;
    std::vector<Task> tasks;

    /**
     * Inicializa uma tarefa.
     *
     * @param description
     * @return
     */
    Task initializeTask(const std::string &description) {
        printf("\n"
               "================================================================================\n"
               " Initializing task: %s\n"
               "--------------------------------------------------------------------------------\n",
               description.c_str());

        Task task(description);
        tasks.push_back(task);

        return task;
    }

    /**
     * Finaliza uma tarefa.
     *
     * @param task
     */
    static void finalizeTask(Task &task) {
        task.finish = std::chrono::high_resolution_clock::now();
        printf(" Finishing task: %s (%lld ms)\n"
               "================================================================================\n",
               task.description.c_str(),
               std::chrono::duration_cast<std::chrono::milliseconds>(task.finish - task.start).count());
    }
};


#endif //GRAPH_APPS_APPLICATION_H
