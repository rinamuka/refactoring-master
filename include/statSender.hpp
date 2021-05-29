#ifndef INCLUDE_STAT_SENDER_HPP_
#define INCLUDE_STAT_SENDER_HPP_

#include <common.hpp>
#include <fstream>
#include <observer.hpp>
#include <log.hpp>
#include <string>
#include <vector>

class statSender : public observer {
 public:
  statSender() = default;
  virtual ~statSender() = default;

 public:
  void on_data_load(const std::vector<item>&,
                    const std::vector<item>& new_items) override;
  void on_skipped(const item& item = {-1, "inc", -1}) override;
  void on_raw_data_load(const std::vector<std::string>&,
                        const std::vector<std::string>&) override {}

 protected:
  virtual void async_send(const std::vector<item>&, std::string_view);

 private:
  std::ofstream _out_file{"network", std::ios::binary};
};
#endif  // INCLUDE_STAT_SENDER_HPP_