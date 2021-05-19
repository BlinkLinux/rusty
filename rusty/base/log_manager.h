// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_BASE_LOG_MANAGER_H_
#define RUSTY_RUSTY_BASE_LOG_MANAGER_H_

#include <QString>

namespace rusty {

struct LogManagerPrivate;
class LogManager {
 public:
  static LogManager* instance();

  /**
   * Enable console logging.
   */
  void registerConsoleLog();

  /**
   * Enable file logging.
   */
  void registerFileLog();

  /**
   * @param file_limit, rolling log file limits
   */
  void registerFileLog(int file_limit);

  /**
   * Set log format for all of registered log appender.
   *
   * @param format
   */
  void setLogFormat(const QString& format);

  /**
   * Set absolute path to log file.
   * Default is app cache dir. That is $HOME/.cache/ORGANIZATION_NAME/APPLICATION_NAME/APPLICATION_NAME.log
   *  or $HOME/.cache/APPLICATION_NAME/APPLICATION_NAME.log if organization name is not set.
   *
   * @param filepath
   */
  void setLogFilepath(const QString& filepath);

 private:
  explicit LogManager();
  ~LogManager();

  LogManagerPrivate* p_{nullptr};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_BASE_LOG_MANAGER_H_
