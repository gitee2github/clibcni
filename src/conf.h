/******************************************************************************
 * Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * clibcni licensed under the Mulan PSL v1.
 * You can use this software according to the terms and conditions of the Mulan PSL v1.
 * You may obtain a copy of Mulan PSL v1 at:
 *     http://license.coscl.org.cn/MulanPSL
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v1 for more details.
 * Author: tanyifeng
 * Create: 2019-04-25
 * Description: provide conf function definition
 *********************************************************************************/

#ifndef CLIBCNI_CONF_H
#define CLIBCNI_CONF_H

#include "net_conf_list.h"

#ifdef __cplusplus
extern "C" {
#endif

struct network_config {
    net_conf *network;

    char *bytes;
};

struct network_config_list {
    net_conf_list *list;

    char *bytes;
};

void free_network_config(struct network_config *config);

void free_network_config_list(struct network_config_list *conf_list);

int conf_from_bytes(const char *conf_str, struct network_config **config, char **err);

int conf_from_file(const char *filename, struct network_config **config, char **err);

int conflist_from_bytes(const char *json_str, struct network_config_list **list, char **err);

int conflist_from_file(const char *filename, struct network_config_list **list, char **err);

int load_conf(const char *dir, const char *name, struct network_config **conf, char **err);

int conflist_from_conf(const struct network_config *conf, struct network_config_list **conf_list, char **err);

int conf_files(const char *dir, const char * const *extensions, size_t ext_len, char ***result, char **err);

#ifdef __cplusplus
}
#endif

#endif

