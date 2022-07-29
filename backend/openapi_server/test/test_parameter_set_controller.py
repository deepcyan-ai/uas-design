# coding: utf-8

from __future__ import absolute_import
import unittest

from flask import json
from six import BytesIO

from openapi_server.models.null import Null  # noqa: E501
from openapi_server.models.parameter_set import ParameterSet  # noqa: E501
from openapi_server.test import BaseTestCase


class TestParameterSetController(BaseTestCase):
    """ParameterSetController integration test stubs"""

    def test_compute(self):
        """Test case for compute

        compute
        """
        parameter_set = {
  "R_p" : 8.762042,
  "V_l" : 6.878052,
  "V_st" : 5.9448957,
  "M_tip" : 1.1730742,
  "n_S" : 0.8851375,
  "C_dcs" : 9.301444,
  "V_in" : 6.778325,
  "m_total" : 4.9652185,
  "C_D" : 2.302136,
  "E_B" : 4.145608,
  "B_P___M" : 5.962134,
  "S_w" : 3.5571952,
  "P_out" : 9.36931,
  "C_L_max" : 3.6160767,
  "n_P___ideal" : 7.143538,
  "C_L" : 7.0614014,
  "P_in" : 9.965781,
  "Q" : 6.519181,
  "p_a" : 7.05877,
  "T" : 6.965118,
  "B_R_A" : 5.637377,
  "Z" : 0.10263654,
  "V_F" : 2.8841622,
  "m_0" : 5.025005,
  "c" : 2.027123,
  "K_V" : 1.2315135,
  "B_E_a" : 0.8008282,
  "tcs" : 1.284659,
  "g" : 7.386282,
  "B_K_V" : 1.4658129,
  "m_B" : 6.846853,
  "r" : 6.4384236,
  "n_D" : 3.3531933,
  "B_I_0" : 6.0274563,
  "R_a" : 9.018348,
  "W_a" : 6.704019,
  "I_in" : 1.0246457,
  "m_M" : 7.4577446,
  "I_0" : 1.4894159,
  "n_P" : 3.0937452,
  "p_out___max" : 6.6835623
}
        headers = { 
            'Accept': 'application/json',
            'Content-Type': 'application/json',
        }
        response = self.client.open(
            '/v1/compute',
            method='POST',
            headers=headers,
            data=json.dumps(parameter_set),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))


if __name__ == '__main__':
    unittest.main()
