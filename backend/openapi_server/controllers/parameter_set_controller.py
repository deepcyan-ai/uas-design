import connexion
import six

from openapi_server.models.error import Error  # noqa: E501
from openapi_server.models.parameter_set import ParameterSet  # noqa: E501
from openapi_server import util


def compute(parameter_set=None):  # noqa: E501
    """compute

     # noqa: E501

    :param parameter_set: set of parameters
    :type parameter_set: dict | bytes

    :rtype: None
    """
    if connexion.request.is_json:
        parameter_set = ParameterSet.from_dict(connexion.request.get_json())  # noqa: E501
        print(str(parameter_set))
    return 'do some magic!'
